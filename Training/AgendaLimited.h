#pragma once

#include "Agenda.h"
#include <string>
#include "Contact.h"
#include "importExport.h"

class impex AgendaLimited : public Agenda
{
public:
	AgendaLimited();

	
	virtual bool removeContact(std::string name) override;
	virtual const Contact* searchContact(std::string name) override;

protected:
	virtual void addContactImp(const Contact& data) override;

private:
	void initContacts();

private:
	Contact** m_pContacts;
	
};
