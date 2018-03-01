/*
Title:
	BS tree header file
Files:
	BSTtree.h
Semester:
	CMPS 3013--Spring 2018
Author:
	Vincent Rodriguez
Email:
	foxsoccer11@yahoo.com
Description:
	This file is the header file for BSTree.cpp and contains
	the private and public methods as well as a struct node
	definition.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct node
{
	string data;
	node *left;
	node *right;
	node()
	{
		data = "";
		left = NULL;
		right = NULL;
	}
	node(string w)
	{
		data = w;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	node * root;
	int count(node *root);
	void insert(node *&root, node *&temp);
	void print_node(node *n, string label);
	node *minValueNode(node *root);
	node *deleteNode(node *&root, string key);
	int height(node *root);
	void printGivenLevel(node *root, int level);
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);
public:
	BSTree();
	~BSTree();
	int count();
	void insert(string x);
	void deleteNode(string key);
	void minValue();
	int height(string key);
	string top();
	void printLevelOrder();
	void GraphVizOut(string filename);
};

