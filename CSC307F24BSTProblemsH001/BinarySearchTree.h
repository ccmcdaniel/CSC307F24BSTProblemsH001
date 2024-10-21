#pragma once

#include "TreeNode.h"
#include <iostream>
using std::cout;

class BinarySearchTree
{
private:
	TreeNode* root = nullptr;
	int count = 0;


public:
	bool Insert(int data)
	{
		if (root == nullptr)
		{
			root = new TreeNode;
			root->data = data;
			count++;
			return true;
		}
		else
		{
			return Insert(data, root);
		}
	}

	void PrintTree()
	{
		PrintTree(root);
	}


private:
	bool Insert(int data, TreeNode* node)
	{
		if (node->data == data)
			return false;
		else if (node->data > data)
		{
			//Look at the left side.

			//Check to see if a left child exists
			if (node->leftChild != nullptr)
			{
				return Insert(data, node->leftChild);
			}
			else
			{
				//If left side is empty, insert at the left.
				TreeNode* new_node = new TreeNode;
				new_node->data = data;
				new_node->parent = node;
				node->leftChild = new_node;
				count++;
				return true;

			}
		}
		else
		{
			//Look at the right side

			//Check to see if a right child exists
			if (node->rightChild != nullptr)
			{
				return Insert(data, node->rightChild);
			}
			else
			{
				//If left side is empty, insert at the left.
				TreeNode* new_node = new TreeNode;
				new_node->data = data;
				new_node->parent = node;
				node->rightChild = new_node;
				count++;
				return true;

			}
		}
	}

	void PrintTree(TreeNode* node)
	{
		if (node == nullptr)
			return;

		cout << node->data << ", ";
		PrintTree(node->leftChild);
		PrintTree(node->rightChild);
	}

};