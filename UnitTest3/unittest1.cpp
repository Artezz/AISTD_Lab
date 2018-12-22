#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AISTD_Lab3/Include.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Разместите здесь код своего теста
			Assert::IsTrue(compare(test, test2));
		}

	};
}