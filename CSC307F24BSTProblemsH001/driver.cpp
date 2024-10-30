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
	my_bst.Insert(99);
	my_bst.Insert(98);
	my_bst.Insert(97);
	my_bst.Insert(18);
	
	cout << "Before Saving to File: ";
	my_bst.PrintTree();
	cout << "\n";

	my_bst.SaveToFile("my_bst.txt");
	my_bst.LoadFromFile("my_bst.txt");

	cout << "After Loading from File: ";
	my_bst.PrintTree();
	cout << "\n";



	/*while (true)
	{
		int num;

		cout << "\n";
		cout << "Give me a number: ";
		cin >> num;

		if (my_bst.Search(num) == true)
			cout << "The number \"" << num << "\" is in the tree.";
		else
			cout << "The number \"" << num << "\" is NOT in the tree.";
	}*/

	//my_bst.Remove(60);
	//my_bst.PrintTree();
	//cout << "\n";

	//my_bst.Remove(15);
	//my_bst.PrintTree();
	//cout << "\n";

	//my_bst.Remove(20);
	//my_bst.PrintTree();
	//cout << "\n";

	//my_bst.Remove(90);
	//my_bst.PrintTree();
	//cout << "\n";

	//my_bst.Remove(45);
	//my_bst.PrintTree();
	//cout << "\n";
}