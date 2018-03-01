/*
Title:
	Crazy Words Creator
Files:
	generate_words.cpp
Semester:
	CMPS 3013--Spring 2018
Author:
	Vincent Rodriguez
Email:
	foxsoccer11@yahoo.com
Description:
	The purpose of this program is to process lists of
	adjectives, adverbs, animals, nouns, and verbs into
	separate arrays. Then, the program will generate
	crazy words ranging from 3 to 5 words in length. These
	words will be processed into the tenThousandWords array.
	Finally, these ten thousand words will be printed to an
	outfile called tenthousandwords.txt.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//problem when including second header file: redefining struct definition
//#include "AVLtree.h"
//#include "BSTree.h"

using namespace std;

int main() {
	ofstream outfile;
	outfile.open("tenthousandwords.txt");

	//arrays for groups of words
	string *adjArray = new string[15571];
	string *advArray = new string[3237];
	string *animalArray = new string[235];
	string *nounArray = new string[53737];
	string *verbArray = new string[12018];

	//array for the ten thousand crazy words
	string *tenThousandWordsArray = new string[10000];

	string adj = "", adv = "", animal = "", noun = "", verb = "";
	char character;

	int counter = 0;
	int adjCounter = 0, advCounter = 0, animalCounter = 0,
		nounCounter = 0, verbCounter = 0;

	//segment of code that will insert adjectives into array
	ifstream infile;
	infile.open("adjectives.txt");
	while (!infile.eof() && counter < 15571) {
		character = infile.get();
		while (character != '\n') {
			adj = adj + character;
			character = infile.get();
		}
		adjArray[counter] = adj;
		adj = "";
		counter++;
		adjCounter++;
	}
	counter = 0;
	infile.close();

	//segment of code that will insert adverbs into array
	infile.open("adverbs.txt");
	while (!infile.eof() && counter < 3237) {
		character = infile.get();
		while (character != '\n') {
			adv = adv + character;
			character = infile.get();
		}
		advArray[counter] = adv;
		adv = "";
		counter++;
		advCounter++;
	}
	counter = 0;
	infile.close();

	//segment of code that will insert animals into array
	infile.open("animals.txt");
	while (!infile.eof() && counter < 235) {
		character = infile.get();
		while (character != '\n') {
			animal = animal + character;
			character = infile.get();
		}
		animalArray[counter] = animal;
		animal = "";
		counter++;
		animalCounter++;
	}
	counter = 0;
	infile.close();

	//segment of code that will insert nouns into array
	infile.open("nouns.txt");
	while (!infile.eof() && counter < 53737) {
		character = infile.get();
		while (character != '\n') {
			noun = noun + character;
			character = infile.get();
		}
		nounArray[counter] = noun;
		noun = "";
		counter++;
		nounCounter++;
	}
	counter = 0;
	infile.close();

	//segment of code that will insert verbs into array
	infile.open("verbs.txt");
	while (!infile.eof() && counter < 12018) {
		character = infile.get();
		while (character != '\n') {
			verb = verb + character;
			character = infile.get();
		}
		verbArray[counter] = verb;
		verb = "";
		counter++;
		verbCounter++;
	}
	counter = 0;
	infile.close();

	//segment of code will create array of 10,000 crazy words,
	//each containing between 3 and 5 words of varying type
	for (int x = 0; x < 10000; x++) {
		string newWord = "";
		//numWords is the number of words that each crazy word will contain
		//chosenArray will choose one of the arrays to choose a word from
		int numWords, chosenArray;
		numWords = rand() % 3 + 3;
		for (int a = 1; a <= numWords; a++) {
			chosenArray = rand() % 5 + 1;
			if (chosenArray == 1)
				newWord = newWord + adjArray[rand() % adjCounter];
			else if (chosenArray == 2)
				newWord = newWord + advArray[rand() % advCounter];
			else if (chosenArray == 3)
				newWord = newWord + animalArray[rand() % animalCounter];
			else if (chosenArray == 4)
				newWord = newWord + nounArray[rand() % nounCounter];
			else {
				newWord = newWord + verbArray[rand() % verbCounter];
			}
			newWord = newWord + " ";
		}
		tenThousandWordsArray[x] = newWord;
	}

	//outfiles the 10,000 crazy words
	for (int x = 0; x < 10000; x++) {
		outfile << tenThousandWordsArray[x] << endl;
	}

	//operator delete function found at
	//http://www.cplusplus.com/reference/new/operator%20delete[]/
	void operator delete[](void* adjArray) noexcept;
	void operator delete[](void* advArray) noexcept;
	void operator delete[](void* animalArray) noexcept;
	void operator delete[](void* nounArray) noexcept;
	void operator delete[](void* verbArray) noexcept;
	void operator delete[](void* tenThousandWordsArray) noexcept;

	system("pause");
	return 0;
}
