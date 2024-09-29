#include "pch.h"
#include "CppUnitTest.h"
#include "../Training/AgendaLimited.h"
#include "../Training/AgendaList.h"
#include "Utilities.h"

#pragma warning( disable : 4251 )

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestsAL)
	{
	public:

		void AddContact(Agenda* pAgenda)
		{
			pAgenda->addContact(Contact("Ana"));
		}

		TEST_METHOD(createAgendaList)
		{
			Agenda* pAgenda = new AgendaLimited();
			Agenda* pAgenda2 = new AgendaList();
			AddContact(pAgenda);
			AddContact(pAgenda2);
		}
		
		TEST_METHOD(addContactToAgendaList)
		{
			Contact ct;
			AgendaList ag;
			ag.addContact(ct);
		}

		TEST_METHOD(findContactInAgendaList)
		{
			Contact ct;
			ct.setName("Dorel");
			ct.setNumber("0712345678");
			AgendaList ag;

			ag.addContact(ct);
			const Contact* res = ag.searchContact("Dorel");

			Assert::IsNotNull(res);
			Assert::AreEqual(std::string("0712345678"), res->getNumber());
		}

		TEST_METHOD(add10xContactToAgendaList)
		{
			//add contact only once by name
			Contact ct("Dani");

			AgendaList ag;
			Assert::AreEqual(0u, ag.numContacts());

			for (int i = 0; i < 10; i++)
			{
				ag.addContact(ct);
			}

			Assert::AreEqual(1u, ag.numContacts());

			//add more contacts
			for (int i = 0; i < 9; i++)
			{
				Contact currCt;
				std::string currName = "plm";
				currName += std::to_string(i);
				currCt.setName(currName);

				ag.addContact(currCt);

			}

			Assert::AreEqual(10u, ag.numContacts());
		}

		TEST_METHOD(delContactFromEmptyAgendaList)
		{
			//add contact only once by name
			AgendaList ag;
			bool bDel = ag.removeContact("Dani");
			Assert::AreEqual(0u, ag.numContacts());
			Assert::IsFalse(bDel);
		}

		TEST_METHOD(delContactFromAgendaList)
		{
			//add contact only once by name
			AgendaList ag;
			Contact Dani;
			Dani.setName("Dani");
			ag.addContact(Dani);

			Contact Ana;
			Ana.setName("Ana");
			ag.addContact(Ana);

			bool bDel = ag.removeContact("Dani");
			Assert::AreEqual(1u, ag.numContacts());
			Assert::IsTrue(bDel);

		}

		TEST_METHOD(add11xContactToAgendaList)
		{
			//add contact only once by name

			AgendaList ag;

			//add more contacts
			for (int i = 0; i < 10; i++)
			{
				Contact currCt;
				std::string currName = "plm";
				currName += std::to_string(i);
				currCt.setName(currName);

				ag.addContact(currCt);

			}

			Assert::AreEqual(10u, ag.numContacts());

			Contact ctx11("Ana");
			ag.addContact(ctx11);

			Assert::AreEqual(11u, ag.numContacts());
		}

		TEST_METHOD(traverseList)
		{
			AgendaList ag;

			ag.addContact(Contact("b"));
			ag.addContact(Contact("e"));
			ag.addContact(Contact("z"));
			ag.addContact(Contact("j"));
			ag.addContact(Contact("x"));
			ag.addContact(Contact("i"));
			ag.addContact(Contact("o"));
			ag.addContact(Contact("m"));
			ag.addContact(Contact("t"));
			ag.addContact(Contact("a"));
			ag.addContact(Contact("k"));

			Utilities::checkTraversal(ag);

		}

	};
}