#pragma once
#include "BinarySearchTree.h"
using std::cin;

int main()
{
	BinarySearchTree my_bst;

	my_bst.Insert(45);
	my_bst.Insert(90);
	my_bst.Insert(20);
	my_bst.Insert(15);
	my_bst.Insert(75);
	my_bst.Insert(60);

	my_bst.PrintTree();
	cout << "\n";

	while (true)
	{
		int num;

		cout << "\n";
		cout << "Give me a number: ";
		cin >> num;

		if (my_bst.Search(num) == true)
			cout << "The number \"" << num << "\" is in the tree.";
		else
			cout << "The number \"" << num << "\" is NOT in the tree.";
	}
}