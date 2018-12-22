#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AISTD_Lab2/Include.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_Push_front1)
		{
			List *test = new List;
			test->head = new Elem(++test->lenght);
			List *test2 = new List;
			test2->push_front();
			Assert::IsTrue(compare(test, test2));
		}
		TEST_METHOD(Test_Push_front2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(2);
			test->head->index = 1;
			test->head->next = new Elem(1);
			test->head->next->index = 2;
			List *test2 = new List;
			test2->push_front();
			test2->push_front();
			Assert::IsTrue(compare(test, test2));


		}
		TEST_METHOD(Test_Push_back1)
		{
			List *test = new List;
			test->lenght = 1;
			test->head = new Elem(1);
			List *test2 = new List;
			test2->push_back();
			Assert::IsTrue(compare(test, test2));


		}
		TEST_METHOD(Test_Push_back2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(1);
			test->head->next = new Elem(2);
			List *test2 = new List;
			test2->push_back();
			test2->push_back();
			Assert::IsTrue(compare(test, test2));


		}
		TEST_METHOD(Test_pop_back2)
		{
			List *test = new List;
			test->lenght = 1;
			test->head = new Elem(1);
			List *test2 = new List;
			test2->push_back();
			test2->push_back();
			test2->pop_back();
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_pop_back1)
		{
			List *test = new List;
			List *test2 = new List;
			test2->push_back();
			test2->pop_back();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_pop_back0)
		{
			List *test = new List;
			List *test2 = new List;
			test2->pop_back();
			Assert::IsTrue(test->head == test2->head);


		}
		TEST_METHOD(Test_pop_front2)
		{
			List *test = new List;
			test->lenght = 1;
			test->head = new Elem(1);
			List *test2 = new List;
			test2->push_front();
			test2->push_front();
			test2->pop_front();
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_pop_front0)
		{
			List *test = new List;
			List *test2 = new List;
			test2->pop_front();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_pop_front1)
		{
			List *test = new List;
			List *test2 = new List;
			test2->push_front();
			test2->pop_front();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_get_size1)
		{
			List *test2 = new List;
			test2->push_front();
			Assert::IsTrue(test2->lenght==1);
		}

		TEST_METHOD(Test_get_size0)
		{
			List *test2 = new List;
			Assert::IsTrue(test2->lenght == 0);
		}

		TEST_METHOD(Test_clear2)
		{
			List *test = new List;
			List *test2 = new List;
			test2->push_front();
			test2->push_front();
			test2->clear();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_clear0)
		{
			List *test = new List;
			List *test2 = new List;
			test2->clear();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_reOrg2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(2);
			test->head->index = 1;
			test->head->next = new Elem(1);
			test->head->next->index = 2;
			List *test2 = new List;
			test2->lenght = 2;
			test2->head = new Elem(2);
			test2->head->next = new Elem(1);
			test2->reOrg();
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_reOrg0)
		{
			List *test = new List;
			List *test2 = new List;
			test2->reOrg();
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_set1x999)
		{
			List *test = new List;
			test->lenght=1;
			test->head = new Elem(999);
			test->head->index = 1;
			List *test2 = new List;
			test2->push_front();
			test2->set(1, 999);
			Assert::IsTrue(compare(test, test2));
		}
		TEST_METHOD(Test_set0x999)
		{
			List *test = new List;
			List *test2 = new List;
			test2->set(0, 999);
			Assert::IsTrue(test->head == test2->head);
		}

		TEST_METHOD(Test_insert1)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(2);
			test->head->index = 1;
			test->head->next = new Elem(1);
			test->head->next->index = 2;
			List *test2 = new List;
			test2->push_front();
			test2->insert(1);
			Assert::IsTrue(compare(test, test2));
		}
		TEST_METHOD(Test_insert0)
		{
			List *test = new List;
			test->lenght = 1;
			test->head = new Elem(1);
			List *test2 = new List;
			test2->insert(1);
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_swap2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(1);
			test->head->next = new Elem(2);
			List *test2 = new List;
			test2->push_front();
			test2->push_front();
			test2->swap(1,2);
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_goTo2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(1);
			test->head->index = 2;
			List *test2 = new List;
			test2->push_front();
			test2->push_front();
			test2->head=test2->goTo(2);
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_goTo0)
		{
			List *test = new List;
			test->lenght = 1;
			List *test2 = new List;
			test2->push_front();
			test2->head = test2->goTo(0);
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_is_Empty_rez0)
		{
			List *test = new List;
			test->lenght = 1;
			test->head = new Elem(1);
			
			Assert::IsTrue(test->is_Empty() == 0);
		}

		TEST_METHOD(Test_is_Empty_rez1)
		{
			List *test = new List;

			Assert::IsTrue(test->is_Empty() == 1);
		}

		TEST_METHOD(Test_at2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(1);
			test->head->next = new Elem(2);

			Assert::IsTrue(test->at(2) == 2);
		}

		TEST_METHOD(Test_remove_Elem2)
		{
			List *test = new List;
			test->lenght = 2;
			test->head = new Elem(1);
			test->head->next = new Elem(3);
			test->head->next->index = 2;
			List *test2 = new List;
			test2->push_back();
			test2->push_back();
			test2->push_back();
			test2->remove(2);
			Assert::IsTrue(compare(test, test2));
		}

		TEST_METHOD(Test_remove_Elem4)
		{
			List *test = new List;
			test->lenght = 3;
			test->head = new Elem(1);
			test->head->next = new Elem(2);
			test->head->next->next = new Elem(3);
			List *test2 = new List;
			test2->push_back();
			test2->push_back();
			test2->push_back();
			test2->remove(4);
			Assert::IsTrue(compare(test, test2));
		}
	};
}
