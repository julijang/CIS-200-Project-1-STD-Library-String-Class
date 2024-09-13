/*
* Author: Julijan Garbek
* Creation Date: 3/15/2024
* Modification Date: 3/26/2024
* Purpose: myString .cpp file with member function definitions
*/

	#pragma warning(disable : 4996)
	#include "myString.h"
	#include <iostream>
	#include <cstring>
	#include <cctype>

	using namespace std;

	// Append paramater to the beginning of the string using mystring.addStart(parameter)
	myString& myString::addStart(const myString& str) {
		int newLen = len + str.len; // Declare the new length of the appended string
		char* newMem = new char[newLen + 1]; // Allocate memory for the new appended string

		strcpy(newMem, str.mem); // Copy the input string to the beginning of the new string
		strcat(newMem, mem); // Concatenate the original string to the end of the new string;

		delete[] mem; // Delete old allocated memory
		mem = newMem; // Update new string
		len = newLen; // Update new string length

		return *this;
	}

	// Append parameter to the end of the string using mystring.addEnd(parameter)
	myString& myString::addEnd(const myString& str) {
		int newLen = len + str.len; // Declare new length of the appended string
		char* newMem = new char[newLen + 1]; // Allocate memory for the new appended string

		strcpy(newMem, mem); // Copy the original string to the beginning of the new string
		strcat(newMem, str.mem); // Concatenate the input string to the end of the new string

		delete[] mem; // Delete old allocated memory
		mem = newMem; // Update new string
		len = newLen; // Update new string length

		return *this;
	}

	myString& myString::partString(const int startPos, const int length) {
		// Check validity of the starting position
		if (startPos < 0 || startPos >= len || length <= 0) {
			delete[] mem;
			len = 0;
			mem = new char[1];
			mem[0] = '\0';
			return *this;
		}
		mem[length] = '\0';

		char* newMem = new char[length + 1]; // Allocate memory for the string to be returned
		int count = 0; // Declare counter

		for (int i = startPos; i < startPos + length; i++) {
			newMem[count] = mem[i]; // Place the character at mem[] location in the newMem[] string
			count++; // Iterate counter
		}
	
		newMem[length] = '\0'; // Terminate the string at counter length

		delete[] mem; // Delete old allocated memory
		mem = newMem; // Update new string
		len = length; // Update new string length

		return *this; // Return the segmented string
	}

	myString& myString::replPartString(const myString& str, const int startPos, const int length) {
		// Test for an invalid start position
		if (startPos < 0 || startPos >= len || length <= 0) {
			return *this;
		}

		int finalLen = len + length; // 8 in bookworm + 6 in length = book|eating|worm = 14 indeces
		char* finalMem = new char[finalLen + 1]; // Allocate 15

		for (int i = 0; i < startPos; i++) { // startPos = 4. iterate 0, 1, 2, 3
			finalMem[i] = mem[i];
		}

		int count = 0;
		for (int i = startPos; i < (startPos + length); i++) { // startPos + length = 10. Iterate 4, 5, 6, 7, 8, 9
			finalMem[i] = str.mem[count];
			count++;
		}

		count = 0;
		for (int i = startPos + length; i < finalLen; i++) { // startPos + length = 10. Iterate 10, 11, 12, 13
			finalMem[i] = mem[len - startPos + count];
			count++;
		}

		finalMem[finalLen] = '\0'; // Place \0 at 14

		delete[] mem; // Clear previously allocated memory
		mem = finalMem; // Update mem pointer
		len = finalLen; // Update new string length

		return *this; // Return updated string
	}

	myString& myString::replWholeString(const myString& str) {
		// Test to make sure there is no redundancy in the string that is being replaced
		if (this == &str) {
			return *this; // Return itself if the string is duplicate
		}

		delete[] mem; // Clear previously allocated memory
		len = str.len; // Update new string length
		mem = new char[len + 1]; // Create new memory allocation
		strcpy(mem, str.mem); // Copy the string contents to new memory allocation
		mem[len] = '\0'; // Null string terminator

		return *this;
	}

	int myString::compareString(const myString& str) {
		int minLength = min(len, str.len); // Minimum search length
		int offset = 0;
		// Compare the two strings
		for (int i = 0; i < minLength; i++) {
			if (mem[i] != str.mem[i]) {
				offset = i + 1; // Return the index where the strings differ (if exists)
				i = minLength;
			}
		}

		// If the lengths are equal and no differences are found, output which comes first alphabetically (+ / -)
		for (int i = 0; i < len; i++) {
			if (mem[i] < str.mem[i]) {
				return offset; // Return a negative index if the current string is alphabetically before the compared string
			}
			else if (mem[i] > str.mem[i]) {
				return -1 * offset; // Return the index of the differing character if the current string is alphabetically after the compared string
			}
		}

		return 0; // Strings are identical
	}

	void myString::initString() {
		delete[] mem; // Delete allocated memory
		len = 0; // Initialize length to 0
		mem = new char[1]; // Re-allocate memory
		mem[0] = '\0'; // Initialize memory with null terminator variable
	}

	myString& myString::setString(const string& str) {
		delete[] mem; // Clear preallocated memory

		int inputLen = 0;
		while (str[inputLen] != '\0') { // Find the number of elements in the inputted string
			inputLen++;
		}

		len = inputLen; // Update myString length
		mem = new char[len + 1]; // Re-allocate memory

		for (int i = 0; i < len; i++) { // Add every indexed character in the string to myString
			mem[i] = str[i];
		}

		mem[len] = '\0'; // Null string terminator

		return *this;
	}

	myString myString::getString() const {
		myString mystring;

		mystring.len = len; // Declare length of placeholder myString
		mystring.mem = new char[len + 1]; // Allocate memory for placeholder myString

		for (int i = 0; i < len; i++) { // Add every indexed character in myString to placeholder myString
			mystring.mem[i] = mem[i];
		}

		mystring.mem[len] = '\0'; // Null string terminator

		return mystring;
	}

	void myString::printStringScreen() {
		cout << mem << endl; // Output data value
	}

	bool myString::numericString() {
		bool hasDecimal = false;
		bool hasSign = false;

		for (int i = 0; i < len; i++) {
			if (!isdigit(mem[i])) {
				if (mem[i] == '.') { // Check for decimal
					if (hasDecimal) {
						return false; 
					}
					hasDecimal = true;
				}
				else if (mem[i] == '+' || mem[i] == '-') {
					if (hasSign || i != 0) { // Check for modifiers
						return false;  
					}
					hasSign = true;
				}
				else {
					return false;  // Neither a digit nor a valid modifier
				}
			}
		}
		return true; // Return true when input meets requirements as an integer
	}

	bool myString::alphabeticString() {
		for (int i = 0; i < len; i++) {
			if (!isalpha(mem[i])) { // Check each index for non-alphabetic characters
				return false;
			}
		}
		return true; // Return true for alphabetic string
	}