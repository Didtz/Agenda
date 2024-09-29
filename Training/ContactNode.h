
#pragma once

#include "Contact.h"

class ContactNode
{
public:

	ContactNode();
	ContactNode(const Contact& ct);

	ContactNode* next();
	void setNext(ContactNode* pNode);
	const Contact& getContact();

private:

	Contact m_Contact;
	ContactNode* m_pNext;
};

