

#include "pch.h"
#include "CppUnitTest.h"
#include "../Training/AgendaLimited.h"

#pragma warning( disable : 4251 )

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(createAgendaLimited)
		{
			AgendaLimited ag;
		}

		TEST_METHOD(addContactToAgendaLimited)
		{
			Contact ct;
			AgendaLimited ag;
			ag.addContact(ct);
		}

		TEST_METHOD(findContactInAgendaLimited)
		{
			Contact ct;
			ct.setName("Dorel");
			ct.setNumber("0712345678");
			AgendaLimited ag;

			ag.addContact(ct);
			const Contact* res = ag.searchContact("Dorel");

			Assert::IsNotNull(res);
			Assert::AreEqual(std::string ("0712345678") , res->getNumber());
		}

		TEST_METHOD(add10xContactToAgendaLimited)
		{
			//add contact only once by name
			Contact ct("Dani");

			AgendaLimited ag;
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

		TEST_METHOD(delContactFromEmptyAgendaLimited)
		{
			//add contact only once by name
			AgendaLimited ag;
			bool bDel = ag.removeContact("Dani");
			Assert::AreEqual(0u, ag.numContacts());
			Assert::IsFalse(bDel);
		}

		TEST_METHOD(delContactFromAgendaLimited)
		{
			//add contact only once by name
			AgendaLimited ag;
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

		TEST_METHOD(validContact)
		{
			Contact ct;
			Assert::IsFalse(ct.isValid());

			Contact ct2("Ana");
			Assert::IsTrue(ct2.isValid());

			Contact ct3("","123");
			Assert::IsTrue(ct3.isValid());
		}

		TEST_METHOD(add11xContactToAgendaLimited)
		{
			//add contact only once by name
			
			AgendaLimited ag;

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

			Assert::AreEqual(10u, ag.numContacts());
		}
	};
}
