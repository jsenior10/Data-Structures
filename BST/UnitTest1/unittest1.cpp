#include "stdafx.h"
#include "CppUnitTest.h"
#include "../210CT-Coursework/bst.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::string item = "who";
			importTxt();
			BinTreeNode* t = tree_insert(0, words.front());
			for (int i = 1; i < words.size(); i++)
				//starts at second place of vector because the line above adds the first word
				tree_insert(t, words.at(i));
			//std::vector<std::string> ans = { "aa" };
			Assert::IsTrue(searchResult(t, item));
			std::string item2 = "touch";
			Assert::IsTrue(searchResult(t, item2));
		}

		TEST_METHOD(testPreorder)
		{
			/*std::vector<std::string> corAns = { "a","b","d","e","c" };
			BinTreeNode* t = tree_insert(0, "a");
			tree_insert(t, "b");
			tree_insert(t, "c");
			tree_insert(t, "d");
			tree_insert(t, "e");
			Assert::AreSame(preorder(t) == corAns);*/
		}
	};
}
