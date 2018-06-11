/*
Written by: Nicholas Cockcroft
Date: June 11, 2018

Description: A common rule in the English language is "'i' before 'e'
except after 'c'. The goal of this program is to read in inputs from the user
and check to see if it is following this rule of "i before e". There are some
exceptions in the English dictionary but they will be disreguarded. For more details
refer to: https://www.reddit.com/r/dailyprogrammer/comments/8q96da/20180611_challenge_363_easy_i_before_e_except/

Also: Option 1 is completed with this program (refer to reddit post for details)
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check(string word); // Checks if a word is following the "i before e" rule

int main() {

	bool result;
	int count = 0;

	// Attempt to open the file containing the list of words
	ifstream readEnable1;
	readEnable1.open("enable1.txt");

	// If it doesn't exist, let the user know and exit
	if (!readEnable1) {
		cout << "Error, file does not exist." << endl;
		system("pause");
		exit(1);
	}

	// Go through each word and check to see if it follows the rule
	string fileWord;
	while (readEnable1 >> fileWord) {

		result = check(fileWord);

		if (!result) {
			count++;
		}
	}

	cout << "Words not following the 'i before e' rule: " << count << endl;
	system("pause");

	return 0;
}

// A word is passed in as the argument and checks to see if it follows the "i before e" rule
bool check(string word) {

	bool isTrue = true;
	char prevLetter = ' ';

	// Goes through each character of a word check for the letters c, i, or e
	for (size_t i = 0; i < word.length(); i++) {

		// This if block is checking if there is a c in the word and if it is following the rule
		if (word[i] == 'c' && i + 2 < word.length()) {
			if (word[i + 1] == 'i' && word[i + 2] == 'e') {
				return false;
			}

		}

		// This if block is checking for just the letters i and e
		if (word[i] == 'i' || word[i] == 'e' && i + 1 < word.length()) {
			if (word[i] == 'e' && word[i + 1] == 'i' && prevLetter != 'c') {
				return false;
			}
		}
		prevLetter = word[i];

	}

	return isTrue;

}