#include "pch.h"
#include "Utilities.h"
#include "vector"
#include "../Training/IContactCollector.h"
#include "../Training/Agenda.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Utilities::checkTraversal(const Agenda& ag)
{
	class Collector :public IContactCollector
	{
	public:
		std::vector<Contact> contacts;

		void addContact(const Contact& ct) override
		{
			contacts.push_back(ct);
		}
	};

	Collector clt;
	ag.traverseInOrder(&clt);

	Assert::AreEqual(ag.numContacts(), (unsigned int)clt.contacts.size());

	int nContacts = ag.numContacts();

	for (int i = 1; i < nContacts; i++)
	{
		Assert::IsTrue(clt.contacts[i - 1] < clt.contacts[i]);
	}
}