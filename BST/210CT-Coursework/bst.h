#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <fstream>
#include <vector>

std::vector<std::string> words;
std::vector<std::string> pathTraversed;

/*
Title: Binary Tree Implementation
Author: Hintea, D.
Date: 2018
Availability: http://moodle.coventry.ac.uk
*/

class BinTreeNode
{
public:
	BinTreeNode(std::string value)
	{
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
		this->count = 1;
	}

	std::string value;
	int count;
	BinTreeNode* left;
	BinTreeNode* right;
	const BinTreeNode* GetRoot() const;
private:
	BinTreeNode * root = nullptr;
};

BinTreeNode* tree_insert(BinTreeNode* tree, std::string item) //O(h) h = height
{
	if (tree == nullptr)
		tree = new BinTreeNode(item);
	else if (item == tree->value)
	{
		(tree->count)++;
	}

	else if (item < tree->value)
		if (tree->left == nullptr)
			tree->left = new BinTreeNode(item);
		else
			tree_insert(tree->left, item);
	else if (tree->right == nullptr)
		tree->right = new BinTreeNode(item);
	else
		tree_insert(tree->right, item);
	return tree;
}

bool search(BinTreeNode* tree, std::string item) //O(1)
{
	if (tree == nullptr || tree->value == item)
		return tree, true;

	if (item > tree->value)
	{
		pathTraversed.push_back(tree->value);
		return search(tree->right, item), true;
	}
	if (item < tree->value)
	{
		pathTraversed.push_back(tree->value);
		return search(tree->left, item), true;
	}
	pathTraversed.push_back("\nItem is not in the tree.");
	return false;
}

bool searchResult(BinTreeNode* tree, std::string item)
{
	if (search(tree, item))
	{
		std::cout << "yes\n";
		return true;
	}
	else
	{
		std::cout << "no\n"; // shows up before the path traversed does
		return false;
	}
}

BinTreeNode* findLowestValueNode(BinTreeNode* tree) // O(h)
{
	BinTreeNode* curr = tree;
	while (curr->left != nullptr)
		curr = curr->left;
	return curr;
}

BinTreeNode* tree_delete(BinTreeNode* tree, std::string item) //O(h)
{
	if (tree == nullptr)
		return tree;
	if (item < tree->value)
		tree->left = tree_delete(tree->left, item); // item < tree->value then item is in left subtree
	else if (item > tree->value)
		tree->right = tree_delete(tree->right, item); // item > tree->value then item is in right subtree

	else
	{
		if (tree->count > 1)
		{
			(tree->count)--;
			return tree;
		}

		//handles nodes with 1 or 0 children
		if (tree->left == nullptr)
		{
			BinTreeNode* temp = tree->right;
			delete[] tree;
			return temp;
		}
		if (tree->right == nullptr)
		{
			BinTreeNode* temp = tree->left;
			delete[] tree;
			return temp;
		}

		BinTreeNode* temp = findLowestValueNode(tree->right);
		tree->value = temp->value;
		tree->right = tree_delete(tree->right, temp->value);
	}
	return tree;
}


void postorder(BinTreeNode* tree) // O(h)
{
	if (tree->left != nullptr)
		postorder(tree->left);
	if (tree->right != nullptr)
		postorder(tree->right);
	std::cout << tree->value << tree->count << std::endl;
}

void in_order(BinTreeNode* tree) //O(h)
{
	if (tree->left != nullptr)
		in_order(tree->left);
	std::cout << tree->value << " (" << tree->count << ")" << std::endl;
	if (tree->right != nullptr)
		in_order(tree->right);
}

void preorder(BinTreeNode* tree) // O(h)
{
	if (tree == nullptr)
	{
		return;
	}
	std::cout << tree->value << "\n";
	preorder(tree->left);
	preorder(tree->right);
}

void importTxt() // O(n)
{
	//puts all words from text file into words vector
	std::string temp;
	std::ifstream txt;
	txt.open("../text.txt");
	while (txt >> temp)
	{
		words.push_back(temp);
	}
	//words.erase(std::remove_if(words.begin(), words.end(), ispunct)); // remove all punctuation and also the white space left from removing it
	txt.close();
}
