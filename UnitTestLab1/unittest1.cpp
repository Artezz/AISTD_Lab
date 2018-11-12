#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AISTD_Lab/Include.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTestLab1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_equal_3x3_eq_arr1)
		{
			int arrT[3][3] = { {1,1,1,},{1,2,1},{1,1,1} };
			Array arr; 
			arr.row = 3;
			arr.col = 3;
			arr.firstN = 1;
			arr.createArr();
			arr.fillArr();
			Assert::IsTrue(is_equal(reinterpret_cast<int*> (arrT), 3, 3, arr.arr,3,3));
		}
		TEST_METHOD(is_equal_2x3_and_3x3_eq_arr)
		{
			int arrT[3][3] = { { 1,1,1, },{ 1,2,1 },{ 1,1,1 } };
			Array arr;
			arr.row = 2;
			arr.col = 3;
			arr.firstN = 1;
			arr.createArr();
			arr.fillArr();
			Assert::IsFalse(is_equal(reinterpret_cast<int*> (arrT), 2, 3, arr.arr, 3, 3));
		}
		TEST_METHOD(is_equal_3x2_and_3x3_eq_arr)
		{
			int arrT[3][3] = { { 1,1,1, },{ 1,2,1 },{ 1,1,1 } };
			Array arr;
			arr.row = 3;
			arr.col = 2;
			arr.firstN = 1;
			arr.createArr();
			arr.fillArr();
			Assert::IsFalse(is_equal(reinterpret_cast<int*> (arrT), 3, 2, arr.arr, 3, 3));
		}
		TEST_METHOD(is_equal_3x3_and_3x3_neq_arr)
		{
			int arrT[3][3] = { { 1,1,1, },{ 1,2,1 },{ 1,1,1 } };
			Array arr;
			arr.row = 3;
			arr.col = 3;
			arr.firstN = 0;
			arr.createArr();
			arr.fillArr();
			Assert::IsFalse(is_equal(reinterpret_cast<int*> (arrT), 3, 3, arr.arr, 3, 3));
		}
		TEST_METHOD(is_equal_3x3_eq_arr0)
		{
			int arrT[3][3] = { { 0,0,0, },{ 0,1,0 },{ 0,0,0 } };
			Array arr;
			arr.row = 3;
			arr.col = 3;
			arr.firstN = 0;
			arr.createArr();
			arr.fillArr();
			Assert::IsTrue(is_equal(reinterpret_cast<int*> (arrT), 3, 3, arr.arr, 3, 3));
		}
		TEST_METHOD(is_equal_1x1_eq_arr1)
		{
			int arrT[1][1] = { 1 };
			Array arr;
			arr.row = 1;
			arr.col = 1;
			arr.firstN = 1;
			arr.createArr();
			arr.fillArr();
			Assert::IsTrue(is_equal(reinterpret_cast<int*> (arrT), 1, 1, arr.arr, 1, 1));
		}
		//reinterpret_cast<int*> (arrT)
	};
}