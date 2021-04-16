#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.1(A)/Product.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51A
{
	TEST_CLASS(UnitTestLab51A)
	{
	public:
		
		TEST_METHOD(Unit_Test_power)
		{
			Product a(200, 2.3);
			Assert::AreEqual(a.power(), 4600.0);
		}
	};
}