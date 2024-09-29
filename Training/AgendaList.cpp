#include "AgendaList.h"
#include "IContactCollector.h"
#include "vector"
#include "algorithm"

AgendaList::AgendaList()
{
	m_pFirst = NULL;
}

void AgendaList::addContactImp(const Contact& data)
{
	m_nNumContacts++;

	if (NULL == m_pFirst)
	{
		m_pFirst = new ContactNode(data);
	}
	else
	{
		ContactNode* pNewNode = new ContactNode(data);

		ContactNode* pLastNode = m_pFirst;
		while (NULL != pLastNode->next())
		{
			pLastNode = pLastNode->next();
		}

		pLastNode->setNext(pNewNode);
	}
}

bool AgendaList::removeContact(std::string name)
{
	bool bRet = false;
	ContactNode* pCurrNode = m_pFirst;
	ContactNode* pPrevNode = NULL;

	while (NULL != pCurrNode)
	{
		if (pCurrNode->getContact().getName() == name)
		{
			if (NULL != pPrevNode)
			{
				pPrevNode->setNext(pCurrNode->next());
			}
			else
			{
				m_pFirst = pCurrNode->next();
			}
			
			delete pCurrNode;

			bRet = true;
			m_nNumContacts--;
			break;
		}

		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->next();
	}

	return bRet;
}

const Contact* AgendaList::searchContact(std::string name)
{
	const Contact* pRet = NULL;
	ContactNode* pCurrNode = m_pFirst;

	while (NULL != pCurrNode)
	{
		if (pCurrNode->getContact().getName() == name)
		{
			pRet = &(pCurrNode->getContact());
			break;
		}

		pCurrNode = pCurrNode->next();
	}

	return pRet;
}

void AgendaList::traverseInOrder(IContactCollector* pCollector) const
{
	ContactNode* pCurrNode = m_pFirst;

	class Collector :public IContactCollector
	{
	public:
		std::vector<Contact> contacts;

		void addContact(const Contact& ct) override
		{
			contacts.push_back(ct);
		}
	};

	Collector interm;

	while (NULL != pCurrNode)
	{
		interm.addContact(pCurrNode->getContact());

		pCurrNode = pCurrNode->next();
	}

	std::sort(interm.contacts.begin(), interm.contacts.end());

	for (const Contact& curr : interm.contacts)
	{
		pCollector->addContact(curr);
	}
}
