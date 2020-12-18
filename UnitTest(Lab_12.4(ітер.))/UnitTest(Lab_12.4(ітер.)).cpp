#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4(ітер.)/Lab_12.4(ітер.).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab124ітер
{
	TEST_CLASS(UnitTestLab124ітер)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* L = NULL;
			Spusok* L1 = NULL;
			Spusok* L2 = NULL;
			Spusok* T, * G;

			int x = 0;
			for (int i = -3; i < 3; i++)
			{
				T = L;
				x = i;
				Creata(L, T, x);
			}


			Process(L, L1, L2, T, G);

			T = L1;
			int l = T->inf;
			Assert::AreEqual(l, 1);
		}
	};
}
