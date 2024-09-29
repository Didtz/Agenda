#include "ContactNodeTree.h"

ContactNodeTree::ContactNodeTree()
{
	m_pLeft = NULL;
	m_pRight = NULL;
	m_pParent = NULL;
}

ContactNodeTree::ContactNodeTree(const Contact& ct)
{
	m_Contact = ct;
	m_pLeft = NULL;
	m_pRight = NULL;
	m_pParent = NULL;
}

ContactNodeTree* ContactNodeTree::left()
{
	return m_pLeft;
}

ContactNodeTree* ContactNodeTree::right()
{
	return m_pRight;
}

ContactNodeTree* ContactNodeTree::parent()
{
	return m_pParent;
}

void ContactNodeTree::setLeft(ContactNodeTree* pNode)
{
	m_pLeft = pNode;
}

void ContactNodeTree::setRight(ContactNodeTree* pNode)
{
	m_pRight = pNode;
}

void ContactNodeTree::setParent(ContactNodeTree* pNode)
{
	m_pParent = pNode;
}

const Contact& ContactNodeTree::getContact()
{
	return m_Contact;
}

void ContactNodeTree::print()
{

}