#include "ContactNode.h"

ContactNode::ContactNode()
{
	m_pNext = NULL;
}

ContactNode::ContactNode(const Contact& ct)
{
	m_Contact = ct;
	m_pNext = NULL;
}

ContactNode* ContactNode::next()
{
	return m_pNext;
}

void ContactNode::setNext(ContactNode* pNode)
{
	m_pNext = pNode;
}

const Contact& ContactNode::getContact()
{
	return m_Contact;
}