#include "Agenda.h"

Agenda::Agenda()
{
	m_nNumContacts = 0u;
}

void Agenda::addContact(const Contact& data)
{
	if (!data.isValid())
		return;

	if (NULL == searchContact(data.getName()))
	{
		addContactImp(data);
	}

}

bool Agenda::removeContact(std::string name)
{
	return false;
}

const Contact* Agenda::searchContact(std::string name)
{
	return NULL;
}

unsigned int Agenda::numContacts() const
{
	return m_nNumContacts;
}

void Agenda::traverseInOrder(IContactCollector* pCollector) const
{

}
