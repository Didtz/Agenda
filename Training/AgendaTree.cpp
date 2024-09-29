#include "AgendaTree.h"
#include "stack"
#include "IContactCollector.h"
#include "NodesCollector.h"

AgendaTree::AgendaTree()
{
	m_pRoot = NULL;
}

void AgendaTree::addContactImp(const Contact& data)
{
	m_nNumContacts++;
	ContactNodeTree* pNewNode = new ContactNodeTree(data);
	addContactImp(pNewNode);
}

void AgendaTree::addContactImp(ContactNodeTree* pNewNode)
{
	if (NULL == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		ContactNodeTree* pNode = m_pRoot;
		
		while (true)
		{
			if (pNewNode->getContact() < pNode->getContact())
			{
				if (NULL == pNode->left())
				{
					pNode->setLeft(pNewNode);
					pNewNode->setParent(pNode);
					break;
				}
				else
				{
					pNode = pNode->left();
				}
				
			}
			else
			{
				if (NULL == pNode->right())
				{
					pNode->setRight(pNewNode);
					pNewNode->setParent(pNode);
					break;
				}
				else
				{
					pNode = pNode->right();
				}
			}
		}
	}
}

const Contact* AgendaTree::searchContact(std::string name)
{
	const Contact* pRet=NULL;
	ContactNodeTree* pCurrNode = m_pRoot;

	while (pCurrNode != NULL)
	{
		if (name < pCurrNode->getContact().getName())
		{
			pCurrNode = pCurrNode->left();
		}
		else if (pCurrNode->getContact().getName() == name)
		{
			pRet = &(pCurrNode->getContact());
			break;
		}
		else
		{
			pCurrNode = pCurrNode->right();
		}
	}

	return pRet;
}

bool AgendaTree::removeContact(std::string name)
{
	bool bRet = false;

	ContactNodeTree* pCurrNode = m_pRoot;
	ContactNodeTree* pParent = NULL;
	NodesCollectorKeep readdNodes;

	//find node
	while (pCurrNode != NULL)
	{
		if (name < pCurrNode->getContact().getName())
		{
			pParent = pCurrNode;
			pCurrNode = pCurrNode->left();
		}
		else if (pCurrNode->getContact().getName() == name)
		{
			bRet = true;
			break;
		}
		else
		{
			pParent = pCurrNode;
			pCurrNode = pCurrNode->right();
		}
	}

	if (pCurrNode != NULL)
	{
		//if 2 children choose left to replace father in tree
		//collect other child + all descendents, reintroduce them in tree one by one
		if (pParent != NULL)
		{
			if (pCurrNode == pParent->left())
			{
				if (pCurrNode->left() != NULL)
				{
					pParent->setLeft(pCurrNode->left());
					pCurrNode->left()->setParent(pParent);

					//collect right nodes
					traverseInOrder(&readdNodes, pCurrNode->right());
				}
				else
				{
					pParent->setLeft(pCurrNode->right());
					pCurrNode->right()->setParent(pParent);
				}

			}
			else //del right child
			{

				if (pCurrNode->left() != NULL)
				{
					pParent->setRight(pCurrNode->left());
					pCurrNode->left()->setParent(pParent);

					//collect right nodes
					traverseInOrder(&readdNodes, pCurrNode->right());
				}
				else
				{
					pParent->setRight(pCurrNode->right());
					pCurrNode->right()->setParent(pParent);
				}
			}
		}
		else //del root
		{
			if (m_pRoot->left() != NULL)
			{
				m_pRoot = m_pRoot->left();
				m_pRoot->setParent(NULL);

				//collect right nodes
				traverseInOrder(&readdNodes, pCurrNode->right());
			}
			else
			{
				m_pRoot = m_pRoot->right();
				m_pRoot->setParent(NULL);
			}
		}
		delete pCurrNode;
		m_nNumContacts--;
	}

	//del collected nodes relations
	readdNodes.severRelations();

	//readd now
	for (ContactNodeTree* pNode : readdNodes.getNodes())
	{
		addContactImp(pNode);
	}

	return bRet;
}

ContactNodeTree* findLeftMost(ContactNodeTree* pNode)
{
	while (pNode->left() != NULL)
	{
		pNode = pNode->left();
	}

	return pNode;
}

void AgendaTree::traverseInOrder(IContactCollector* pCollector) const
{
	NodesCollectorForward forwardColl(pCollector);
	traverseInOrder(&forwardColl, m_pRoot);
}

void AgendaTree::traverseInOrder(INodesCollector* pCollector, ContactNodeTree* pNode) const
{
 	std::stack<ContactNodeTree*> parentsStack;

	while (pNode != nullptr)
	{
		while (nullptr != pNode->left())
		{
			parentsStack.push(pNode);
			pNode = pNode->left();
		}

		pCollector->collect(pNode);

		if(nullptr != pNode->right())
			pNode = pNode->right();
		else
		{
			pNode = nullptr;

			while (!parentsStack.empty() && nullptr == pNode)
			{
				ContactNodeTree* pLastParent = parentsStack.top();
				parentsStack.pop();

				pCollector->collect(pLastParent);

				pNode = pLastParent->right();
			}
		}
	}

}
