/*
* Author: Julijan Garbek
* Creation Date: 3/15/2024
* Modification Date: 3/26/2024
* Purpose: myString .h file with class outline
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#pragma warning(disable : 4996)

#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class myString
{
private:

	char* mem; // Buffer assignment variable
	unsigned int len; // Unsigned int is used such that the length of the string cannot be < 0

public:

	myString() : mem(nullptr), len(0) {} // Default constructor
	
	myString(const std::string& str) { // String initialization constructor
		len = str.length(); 
		mem = new char[len + 1]; 
		strcpy(mem, str.c_str()); 
	}

	myString(const myString& mystr) { // Copy constructor
		len = mystr.len;
		mem = new char[len + 1];

		strcpy(mem, mystr.mem);
	}

	~myString() { // Destructor
		delete[] mem; 
	}

	myString& operator=(const myString& other) { // Overload assignment operator
		if (this != &other) {
			delete[] mem;
			len = other.len;
			mem = new char[len + 1];
			strcpy(mem, other.mem);
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const myString& str) { // String output overload operator
		os << str.mem;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, myString& str) { // String input overload operator
		char buffer[1000]; // Declare a maximum input length of 999 characters
		is >> buffer;
		delete[] str.mem;
		str.len = strlen(buffer);
		str.mem = new char[str.len + 1];
		strcpy(str.mem, buffer);
		return is;
	}

	// Member functions
	unsigned int size() const { return len; } // Defined
	myString& addStart(const myString& mystring); // Defined
	myString& addEnd(const myString& mystring); // Defined
	myString& partString(const int startPos, const int length); // Defined
	myString& replPartString(const myString& mystring, const int startPos, const int length); // Defined
	myString& replWholeString(const myString& mystring); // Defined
	int compareString(const myString& mystring); // Defined
	void initString(); // Defined
	myString& setString(const string& mystring); // Defined
	myString getString() const; // Defined
	void printStringScreen(); // Defined
	bool numericString(); // Defined
	bool alphabeticString(); // Defined

};

#endif