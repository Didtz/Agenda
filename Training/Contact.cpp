
#pragma warning( disable : 4251 )

#include "Contact.h"


Contact::Contact()
{
	m_name = "";
	m_number = "";
}

Contact::Contact(std::string name, std::string number)
{
	m_name = name;
	m_number = number;
}

Contact::Contact(const Contact& other)
{
	m_name = other.m_name;
	m_number = other.m_number;
}

std::string Contact::getName() const
{
	return m_name;
}

std::string Contact::getNumber() const
{
	return m_number;
}

void Contact::setName(std::string name)
{
	m_name = name;
}

void Contact::setNumber(std::string number)
{
	m_number = number;
}

bool Contact::isValid() const
{
	if (m_name.empty() && m_number.empty())
		return false;

	return true;
}

bool Contact::operator < (const Contact& other) const
{
	return m_name < other.m_name;
}