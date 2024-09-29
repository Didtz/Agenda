#include "pch.h"
#include "CppUnitTest.h"
#include "../Experiments/A.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestsExp)
	{
	public:

		TEST_METHOD(experiments)
		{
			double dA = 10;
			double dB = dA;
			dB = 20;
			double& dC = dA;
			dC = 30;

			double* pDA = new double();
			*pDA = 10;
			double* pDB = pDA;
			*pDB = 20;
			double*& pDC = pDA;
			*pDC = 30;

			int& nCnt = A::m_nCnt;

			A a;
			a.setVal(10);
			A b(a);
 			b.setVal(20);
			A& c = a;
			c.setVal(30);

			A* pa = new A();
			pa->setVal(10);
			A* pb = pa;
			pb->setVal(20);
			A*& pc = pa;
			pc->setVal(30);
			
			pb = new A();
			pc = new A();
		}

		TEST_METHOD(experiments2)
		{
			int& nCnt = A::m_nCnt;
			{
				A a;
				a.setVal(10);
				A b = a;
				b.setVal(20);
				A& c = a;
				c.setVal(30);
			}
			{
 				A* pa = new A();
				pa->setVal(10);
				A* pb = pa;
				pb->setVal(20);
				A*& pc = pa;
				pc->setVal(30);

				pb = new A();

				delete pa;

				pc = new A();

				delete pa;
				delete pb;
			}
		}
	};
}

