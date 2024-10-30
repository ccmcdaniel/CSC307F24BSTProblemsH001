#pragma once

#include "TreeNode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::stoi;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
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

	bool Search(int data)
	{
		if (root == nullptr)
			return false;
		else
			return Search(data, root);
	}

	bool Remove(int data)
	{
		if (root == nullptr)
			return false;
		else
			return RemoveSearch(data, root);
	}

	void PrintTree()
	{
		PrintTree(root);
	}

	void SaveToFile(string filepath)
	{
		ofstream file;
		file.open(filepath);

		SaveToFile(file, root);

		file.close();
	}

	string LoadFromFile(string filepath, bool append = false)
	{
		try 
		{
			ifstream file;
			file.open(filepath);

			//Read the data from the list.
			vector<int> read_data;

			string line;
			while (getline(file, line))
			{
				int data = stoi(line);
				read_data.push_back(data);
			}


			//Clear the Tree
			if(append == false)
				ClearTree();

			for (int i = 0; i < read_data.size(); i++)
				Insert(read_data[i]);

			file.close();

			return "";
		}
		catch (int e)
		{
			return "Error:  An error occurred while attempting to read the file.";
		}

	}

	void ClearTree()
	{
		ClearTree(root);
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

	bool Search(int data, TreeNode* node)
	{
		if (node == nullptr)
			return false;
		else
		{
			if (node->data == data)
				return true;
			else if (node->data > data)
				return Search(data, node->leftChild);
			else
				return Search(data, node->rightChild);
		}
	}

	bool RemoveSearch(int data, TreeNode* node)
	{
		if (node == nullptr)
			return false;
		else
		{
			if (node->data == data)
			{
				//delete node here
				RemoveNode(node);
				count--;
				return true;
			}
			else if (node->data > data)
				return RemoveSearch(data, node->leftChild);
			else
				return RemoveSearch(data, node->rightChild);
		}
	}

	void RemoveNode(TreeNode* node)
	{
		if (node->leftChild == nullptr && node->rightChild == nullptr)
		{
			//type 1 deletion on a leaf node.
			if (node == root)
			{
				delete root;
				root = nullptr;
				return;
			}
			else
			{
				if (node == node->parent->leftChild)
					node->parent->leftChild = nullptr;
				else
					node->parent->rightChild = nullptr;

				delete node;
				return;

			}
		}
		else if(node->leftChild != nullptr && node->rightChild == nullptr)
		{
			if (node == root)
			{
				root = node->leftChild;
				root->parent = nullptr;
			}
			//type 2 deletion with a left child.
			else if (node == node->parent->leftChild)
			{
				node->parent->leftChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}
			else
			{
				node->parent->rightChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}

			delete node;
			return;
		}
		else if (node->leftChild == nullptr && node->rightChild != nullptr)
		{
			//type 2 deletion with a right child.
			if (node == root)
			{
				root = node->rightChild;
				root->parent = nullptr;
			}
			//type 2 deletion with a right child.
			else if (node == node->parent->leftChild)
			{
				node->parent->leftChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}
			else
			{
				node->parent->rightChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}

			delete node;
			return;
		}
		else // type 3 deletion.
		{
			//perform type 3 deletion
			TreeNode* temp = node->rightChild;

			while (temp->leftChild != nullptr)
				temp = temp->leftChild;

			node->data = temp->data;

			RemoveNode(temp);
			return;
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

	void SaveToFile(ofstream& file, TreeNode* node)
	{
		if (node == nullptr)
			return;

		else
		{
			file << node->data << "\n";
			SaveToFile(file, node->leftChild);
			SaveToFile(file, node->rightChild);
		}
	}

	void ClearTree(TreeNode* node)
	{
		if (node == nullptr)
			return;

		else
		{
			ClearTree(node->leftChild);
			ClearTree(node->rightChild);
			RemoveNode(node);
		}
	}
};