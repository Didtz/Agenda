#include "NodesCollector.h"
#include "IContactCollector.h"
#include "ContactNodeTree.h"


NodesCollectorForward::NodesCollectorForward(IContactCollector* pCtColl)
{
	m_pCtColl = pCtColl;
}


void NodesCollectorForward::collect(ContactNodeTree* pNode)
{
	if (nullptr != m_pCtColl && nullptr != pNode)
	{
		m_pCtColl->addContact(pNode->getContact());
	}
}

NodesCollectorKeep::NodesCollectorKeep()
{
	
}

void NodesCollectorKeep::collect(ContactNodeTree* pNode)
{
	if (nullptr != pNode)
	{
		m_nodes.push_back(pNode);
	}
}

void NodesCollectorKeep::severRelations()
{
	for (ContactNodeTree* pNode : m_nodes)
	{
		pNode->setParent(nullptr);
		pNode->setRight(nullptr);
		pNode->setLeft(nullptr);
	}
}

const std::vector<ContactNodeTree*>& NodesCollectorKeep::getNodes()
{
	return m_nodes;
}