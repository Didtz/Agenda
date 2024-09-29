#pragma once

#include "Agenda.h"
#include "ContactNode.h"

class impex AgendaList : public Agenda
{
public:

	AgendaList();
	
	virtual bool removeContact(std::string name) override;
	virtual const Contact* searchContact(std::string name) override;
	virtual void traverseInOrder(IContactCollector* pCollector) const override;

protected:

	virtual void addContactImp(const Contact& data) override;

private: 

	ContactNode* m_pFirst;
};

