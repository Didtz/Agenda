

#pragma warning( disable : 4251 )

#include "importExport.h"
#include "AgendaLimited.h"

const int maxCtx = 10;

AgendaLimited::AgendaLimited() 
{
	m_pContacts = NULL;
}

void AgendaLimited::initContacts()
{
	if (NULL == m_pContacts)
	{
		m_pContacts = new Contact * [10];

		for (int i = 0; i < maxCtx; i++)
		{
			m_pContacts[i] = NULL;
		}
	}
}
		

void AgendaLimited::addContactImp(const Contact& data)
{
	initContacts();
	
	for (int i = 0; i < maxCtx; i++)
	{
		if (NULL == m_pContacts[i])
		{
			m_pContacts[i] = new Contact(data);
			m_nNumContacts++;
			break;
		}
	}
}

bool AgendaLimited::removeContact(std::string name)
{
	bool bRes = false;
	
	if (NULL != m_pContacts)
	{
		for (int i = 0; i < maxCtx; i++)
		{
			if (NULL != m_pContacts[i])
			{
				if (0 == m_pContacts[i]->getName().compare(name))
				{
					delete m_pContacts[i];
					m_pContacts[i] = NULL;
					bRes = true;
					m_nNumContacts--;
					break;
				}
			}
		}
	}

	return bRes;
}

const Contact* emptyCnt = NULL;

const Contact* AgendaLimited::searchContact(std::string name)
{
	const Contact* pRet = emptyCnt;

	if (NULL != m_pContacts)
	{
		for (int i = 0; i < maxCtx; i++)
		{
			if (NULL != m_pContacts[i])
			{
				if (0 == m_pContacts[i]->getName().compare(name))
				{
					pRet = m_pContacts[i];
					break;
				}
			}
		}
	}

	return pRet;
}
