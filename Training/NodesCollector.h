#pragma once

#include "vector"

class ContactNodeTree;
class IContactCollector;


class INodesCollector
{
public:
	virtual void collect(ContactNodeTree* pNode) = 0;
};

class NodesCollectorForward : public INodesCollector
{
public:

	NodesCollectorForward(IContactCollector* pCtColl);
	
	virtual void collect(ContactNodeTree* pNode) override;

private:
	IContactCollector* m_pCtColl;
};

class NodesCollectorKeep : public INodesCollector
{
public:

	NodesCollectorKeep();

	virtual void collect(ContactNodeTree* pNode) override;
	void severRelations();
	const std::vector<ContactNodeTree*>& getNodes();

private:
	std::vector<ContactNodeTree*> m_nodes;
};
