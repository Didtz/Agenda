#include "pch.h"
#include "CppUnitTest.h"
#include "../Training/AgendaTree.h"
#include "../Training/IContactCollector.h"
#include <vector>
#include "Utilities.h"

#pragma warning( disable : 4251 )

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestsTree)
	{
	public:

		void AddContact(Agenda* pAgenda)
		{
			pAgenda->addContact(Contact("Ana"));
		}

		TEST_METHOD(createAgendaTree)
		{
			Agenda* pAgenda2 = new AgendaTree();
			AddContact(pAgenda2);
		}

		TEST_METHOD(addContactToAgendaTree)
		{
			Contact ct;
			AgendaTree ag;
			ag.addContact(ct);
		}

		TEST_METHOD(findContactInAgendaTree)
		{
			Contact ct;
			ct.setName("Dorel");
			ct.setNumber("0712345678");
			AgendaTree ag;

			ag.addContact(ct);
			const Contact* res = ag.searchContact("Dorel");

			Assert::IsNotNull(res);
			Assert::AreEqual(std::string("0712345678"), res->getNumber());
		}

		TEST_METHOD(add10xContactToAgendaTree)
		{
			//add contact only once by name
			Contact ct("Dani");

			AgendaTree ag;
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

		TEST_METHOD(delContactFromEmptyAgendaTree)
		{
			//add contact only once by name
			AgendaTree ag;
			bool bDel = ag.removeContact("Dani");
			Assert::AreEqual(0u, ag.numContacts());
			Assert::IsFalse(bDel);
		}

		TEST_METHOD(delContactFromAgendaTree)
		{
			//add contact only once by name
			AgendaTree ag;
			Contact Dani;
			Dani.setName("Dani");
			ag.addContact(Dani);

			Contact Ana;
			Ana.setName("Ana");
			ag.addContact(Ana);

			bool bDel = ag.removeContact("Dani");
			Assert::AreEqual(1u, ag.numContacts());
			Assert::IsTrue(bDel);

			const Contact* pCt = ag.searchContact("Dani");
			Assert::IsNull(pCt);

		}

		TEST_METHOD(delContactFromAgendaTree2)
		{
			//add contact only once by name
			AgendaTree ag;

			ag.addContact(Contact("b"));
			ag.addContact(Contact("a"));
			ag.addContact(Contact("c"));

			bool bDel = ag.removeContact("b");
			Assert::AreEqual(2u, ag.numContacts());
			Assert::IsTrue(bDel);

			const Contact* pCta = ag.searchContact("a");
			const Contact* pCtb = ag.searchContact("b");
			const Contact* pCtc = ag.searchContact("c");

			Assert::IsNull(pCtb);
			Assert::IsNotNull(pCta);
			Assert::IsNotNull(pCtc);

		}

		TEST_METHOD(add11xContactToAgendaTree)
		{
			//add contact only once by name

			AgendaTree ag;

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

		TEST_METHOD(traverseTree)
		{
			AgendaTree ag;

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

		TEST_METHOD(traverseTree2)
		{
			AgendaTree ag;

			ag.addContact(Contact("b"));
			
			Utilities::checkTraversal(ag);

		}

		TEST_METHOD(traverseTree3)
		{
			AgendaTree ag;

			Utilities::checkTraversal(ag);

		}

		TEST_METHOD(traverseTree4)
		{
			AgendaTree ag;

			ag.addContact(Contact("b"));
			ag.addContact(Contact("c"));
			ag.addContact(Contact("d"));
			ag.addContact(Contact("e"));

			Utilities::checkTraversal(ag);

		}

		TEST_METHOD(traverseTree5)
		{
			AgendaTree ag;

			ag.addContact(Contact("e"));
			ag.addContact(Contact("d"));
			ag.addContact(Contact("c"));
			ag.addContact(Contact("b"));

			Utilities::checkTraversal(ag);

		}
	};
}

