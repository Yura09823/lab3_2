#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3_2/Button.h"
#include "../lab3_2/Window.h"
#include "../lab3_2/WindowWithButton.h"
#include "../lab3_2/Button.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Button b;
			Assert::AreEqual(10, b.getWidth());
			Assert::AreEqual(10, b.getHeight());
		}
	};
}
