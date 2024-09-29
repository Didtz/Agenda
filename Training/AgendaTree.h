#pragma once
#include "Agenda.h"
#include "ContactNodeTree.h"

class INodesCollector;

class impex AgendaTree : public Agenda
{
public:
	AgendaTree();

	virtual const Contact* searchContact(std::string name) override;
	virtual bool removeContact(std::string name);
	virtual void traverseInOrder(IContactCollector* pCollector) const override;

	void traverseInOrder(INodesCollector* pCollector, ContactNodeTree* pNode) const;
	void addContactImp(ContactNodeTree* pNode);

protected:
	virtual void addContactImp(const Contact& data) override;

private:
	ContactNodeTree* m_pRoot;
	
};

