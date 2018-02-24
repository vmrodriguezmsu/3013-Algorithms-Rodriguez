/*
Title:
	Fix Delete Method
Files:
	main.cpp
Semester:
	CMPS 3013--Spring 2018
Author:
	Vincent Rodriguez
Email:
	foxsoccer11@yahoo.com
Description:
	The purpose of this program is to insert integer values
	into a tree container. While the main.cpp file executes,
	values will be deleted from the root node. The program will
	finally attempt to remove the nodes	with integer values
	of 3,10,27, and 29. The level order of the tree will be
	printed before and after the values are	deleted.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h"
using namespace std;

//http://www.webgraphviz.com/
int main()
{
	srand(2342);

	BSTree B;

	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");
	while (B.top()) {
		cout << "removing: " << B.top() << endl;
		B.deleteNode(B.top());
	}

	B.deleteNode(3);
	B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);
	B.printLevelOrder();

	B.GraphVizOut("after.txt");
	system("pause");
	return 0;
}

