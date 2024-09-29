#pragma once

#include "Contact.h"

class ContactNodeTree
{
public:

	ContactNodeTree();
	ContactNodeTree(const Contact& ct);

	ContactNodeTree* left();
	ContactNodeTree* right();
	ContactNodeTree* parent();

	void setLeft(ContactNodeTree* pNode);
	void setRight(ContactNodeTree* pNode);
	void setParent(ContactNodeTree* pNode);

	const Contact& getContact();
	void print();

private:

	Contact m_Contact;
	ContactNodeTree* m_pLeft;
	ContactNodeTree* m_pRight;
	ContactNodeTree* m_pParent;
	
};

