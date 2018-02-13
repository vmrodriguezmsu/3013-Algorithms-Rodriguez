/*
Title:
	Fix Delete Method
Files:
	BSTree.cpp
Semester:
	CMPS 3013--Spring 2018
Author:
	Vincent Rodriguez
Email:
	foxsoccer11@yahoo.com
Description:
	This file is the .cpp file and contains the function
	definitions for those declared in the .h file.
*/

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "BSTree.h"
using namespace std;

/*
Function: int BSTree::count(node *root)
Purpose: counts how many nodes are in the tree
Parameters: one root node
Input: root node
Returns: integer value
*/
int BSTree::count(node *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}

/*
Function: void BSTree::insert(node *&root, node *&temp)
Purpose: inserts the node that is passed by reference
Parameters: one root node by reference and one temp node by reference
Input: root node, temp node
Returns: N/A
*/
void BSTree::insert(node *&root, node *&temp)
{
	if (!root)
	{
		root = temp;
	}
	else
	{
		if (temp->data < root->data)
		{
			insert(root->left, temp);
		}
		else
		{
			insert(root->right, temp);
		}
	}
}

/*
Function: void BSTree::print_node(node *n, string label = "")
Purpose: prints the node that is being deleted
Parameters: one node, empty string
Input: one node, empty string
Output: prints node
*/
void BSTree::print_node(node *n, string label = "")
{
	if (label != "")
	{
		cout << "[" << label << "]";
	}
	cout << "[[" << n << "][" << n->data << "]]\n";
	if (n->left)
	{
		cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[L][null]\n";
	}
	if (n->right)
	{
		cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[R][null]\n";
	}
}

/*
Function: node* BSTree::minValueNode(node *root)
Purpose: if a node has children, the function finds
		 which child is the youngest
Parameters: one root node
Input: one root node
Returns: current node
*/
node* BSTree::minValueNode(node *root)
{
	node *current = root;

	if (root->right)
	{
		current = root->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
	}
	else if (root->left)
	{
		current = root->left;
		while (current->right != NULL)
		{
			current = current->right;
		}
	}

	return current;
}

/*
Function: node* BSTree::deleteNode(node *&root, int key)
Purpose: to delete the node that is passed in by reference
Parameters: one root node by reference, integer value
Input: one root node by reference, integer value
Returns: deleted root
*/
node* BSTree::deleteNode(node *&root, int key)
{
	if (!root)
	{
		return NULL;
	}
	if (key < root->data)
	{
		cout << "going left" << endl;
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->data)
	{
		cout << "going right" << endl;
		root->right = deleteNode(root->right, key);
	}
	else
	{
		//node has no left child
		if (root->left == NULL)
		{
			node * temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		//node has no right child
		else if (root->right == NULL)
		{
			node * temp = root;
			root = root->left;
			delete temp;
			return root;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		else {
			node *temp = minValueNode(root);

			print_node(temp, "minvaluenode");

			// Copy the inorder successor's content to this node
			root->data = temp->data;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->data);

		}
		return root;
	}
	return root;
}

/*
Function: int BSTree::height(node *root)
Purpose: to calculate the height of the tree
Parameters: one root node
Input: one root node
Returns: integer value
*/
int BSTree::height(node *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		int left = height(root->left);
		int right = height(root->right);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

/*
Function: void BSTree::printGivenLevel(node *root, int level)
Purpose: to print nodes at a given level
Parameters: one root node, integer value
Input: one root node, integer value
Output: prints nodes
*/
void BSTree::printGivenLevel(node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		print_node(root);
	}
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

//************************************************************************
// Method to help create GraphViz code so the expression tree can
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive
// tree traversal.
//************************************************************************
void BSTree::GraphVizGetIds(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizGetIds(nodePtr->left, VizOut);
		VizOut << "node" << nodePtr->data
			<< "[label=\"" << nodePtr->data << "\\n"
			//<<"Add:"<<nodePtr<<"\\n"
			//<<"Par:"<<nodePtr->parent<<"\\n"
			//<<"Rt:"<<nodePtr->right<<"\\n"
			//<<"Lt:"<<nodePtr->left<<"\\n"
			<< "\"]" << endl;
		if (!nodePtr->left)
		{
			NullCount++;
			VizOut << "nnode" << NullCount 
				<< "[label=\"X\",shape=point,width=.15]" << endl;
		}
		GraphVizGetIds(nodePtr->right, VizOut);
		if (!nodePtr->right)
		{
			NullCount++;
			VizOut << "nnode" << NullCount 
				<< "[label=\"X\",shape=point,width=.15]" << endl;
		}
	}
}

//************************************************************************
// This method is partnered with the above method, but on this pass it
// writes out the actual data from each node.
// Don't worry about what this method and the above method do, just
// use the output as your told:)
//************************************************************************
void BSTree::GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizMakeConnections(nodePtr->left, VizOut);
		if (nodePtr->left)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->left->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		if (nodePtr->right)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->right->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}

/*
Function: BSTree::BSTree()
Purpose: constructor that creates a tree container with root node
Parameters: N/A
Input: N/A
Output: N/A
*/
BSTree::BSTree()
{
	root = NULL;
}

/*
Function: BSTree::~BSTree()
Purpose: destructor that destroys a tree container
Parameters: N/A
Input: N/A
Output: N/A
*/
BSTree::~BSTree()
{
}

/*
Function: int BSTree::count()
Purpose: public function calls private function that counts
		 height of the tree
Parameters: N/A
Input: N/A
Returns: integer value
*/
int BSTree::count()
{
	return count(root);
}

/*
Function: void BSTree::insert(int x)
Purpose: public function that creates new temp node
		 with integer value x as its data; calls private
		 insert function with root node and temp node
Parameters: integer value
Input: integer value
Returns: N/A
*/
void BSTree::insert(int x)
{
	node *temp = new node(x);
	insert(root, temp);
}

/*
Function: void BSTree::deleteNode(int key)
Purpose: public function that calls the private delete node
		 function to delete the root and passes the key value
Parameters: integer value
Input: integer value
Returns: N/A
*/
void BSTree::deleteNode(int key)
{
	deleteNode(root, key);
}

/*
Function: void BSTree::minValue(int key)
Purpose: prints the node that is the smallest child of
		 either the tree or a subtree
Parameters: N/A
Input: N/A
Output: prints smallest node of tree or subtree
*/
void BSTree::minValue()
{
	print_node(minValueNode(root), "minVal");
}

/*
Function: int BSTree::height(int key)
Purpose: public function that calls the private function
		 to calculate the height of the tree
Parameters: integer value
Input: integer value
Returns: height of tree
*/
int BSTree::height(int key)
{
	if (key > 0)
	{
		//find node
	}
	else
	{
		return height(root);
	}
	return 0;
}

/*
Function: int BSTree::top()
Purpose: public function that finds the value of the top node
Parameters: N/A
Input: N/A
Returns: integer value
*/
int BSTree::top()
{
	if (root)
		return root->data;
	else
		return 0;
}

/*
Function: void BSTree::printLevelOrder()
Purpose: Function to line by line print level order traversal a tree
Parameters: N/A
Input: N/A
Output: prints nodes by level
*/
void BSTree::printLevelOrder()
{
	cout << "Begin Level Order===================\n";
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		cout << "\n";
	}
	cout << "End Level Order===================\n";
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename);
	VizOut << "Digraph G {\n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}\n";
	VizOut.close();
}

#endif // !BSTREE_H
