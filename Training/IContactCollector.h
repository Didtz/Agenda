#pragma once

class Contact;

class IContactCollector
{
public:
	virtual void addContact(const Contact& ct) = 0;

};

