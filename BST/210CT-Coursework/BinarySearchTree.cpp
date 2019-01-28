#include "stdafx.h"
#include "bst.h"
#include <locale>

int main(int argc, char* argv[])
{
	std::string item;
	importTxt();
	BinTreeNode* t = tree_insert(nullptr, words.front());
	for (int i = 1; i < words.size(); i++) //starts at second place of vector because the line above adds the first word
		tree_insert(t, words.at(i));
	std::cout << "first tree: \n";
	preorder(t);
	tree_delete(t, "the");
	std::cout << "second tree: \n";
	preorder(t);
	std::cout << "What would you like to find?" << std::endl;
	std::getline(std::cin, item);
	/*if(std::cin.fail())
	{
	std::cout << "Please only enter string.\n";
	}
	else {
	if(search(t, item))
	{

	}
	search(t, item);
	}*/
	searchResult(t, item);
	std::cout << "Path traversed for search: " << std::endl;
	for (auto const& buffer : pathTraversed)
		std::cout << buffer << ' ';
	preorder(t);


	/* THIS IS ONLY FOR USER INPUT, ABOVE FUNCTIONS ARE TO HAVE EVERYTHING SET UP EASILY
	int menuChoose;
	while (true) {
	std::cout << "What would you like to do?\n1.Print in pre-order\n2.Print in in-order\n3.Print in post-order\n4.Search for an item in the tree\n5.Delete an item in the tree\n6.Quit\n";
	std::cin >> menuChoose;
	if(menuChoose != 1 || menuChoose != 2 || menuChoose != 3 || menuChoose != 4 || menuChoose != 5 || menuChoose != 6)
	{
	std::cout << "Please choose one of the options";
	}
	if (menuChoose == 1) {
	preorder(t);
	}
	if (menuChoose == 2) {
	in_order(t);
	}
	if (menuChoose == 3) {
	postorder(t);
	}
	if (menuChoose == 4) {
	std::string toSearch;
	std::cout << "What item would you like to search for?\n";
	std::cin >> toSearch;
	search(t, toSearch);
	for (int i = 0; i < pathTraversed.size(); i++)
	{
	std::cout << pathTraversed[i] << " ";
	}
	}
	if (menuChoose == 5)
	{
	std::string toDelete;
	std::cout << "What item would you like to delete?\n";
	std::cin >> toDelete;
	tree_delete(t, toDelete);
	}
	if (menuChoose == 6)
	{
	break;
	}*/
	system("pause");
	return 0; /*
			  }*/
}
