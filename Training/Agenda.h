#pragma once

#include <string>
#include "Contact.h"
#include "importExport.h"

class IContactCollector;

class impex Agenda
{
public:
	Agenda();

	virtual void addContact(const Contact& data);
	virtual bool removeContact(std::string name);
	virtual const Contact* searchContact(std::string name);
	virtual unsigned int numContacts() const;
	virtual void traverseInOrder(IContactCollector* pCollector) const;

protected:
	virtual void addContactImp(const Contact& data) = 0;

protected:
	unsigned int m_nNumContacts;
};

