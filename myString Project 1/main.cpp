/*
* Author: Julijan Garbek
* Creation Date: 3/21/2024
* Modification Date: 3/26/2024
* Purpose: Demonstrate the capabilities of the myString class in relation to the standard c++ string library via user inputs
*/

#include "myString.h"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;
ofstream ofs;

int main() {
    
    // Declare integer to determine user input
	int input;

    // Initial open for log file
    ofs.open("log.txt");
    if (!ofs.is_open()) {
        cerr << "Unable to open log.txt" << endl;
        return 1;
    }
    ofs << setw(20) << left << "Function Call" << " | " << setw(21) << left << "Values" << " | " << setw(20) << left << "Parameters" << endl;
    ofs.close();

    // Initial open for console file
    ofs.open("console.txt");
    if (!ofs.is_open()) {
        cerr << "Unable to open console.txt" << endl;
        return 1;
    }
    ofs << "Console: " << endl;
    ofs.close();

    // User prompt of function options
    cout << "Welcome to the myString class" << endl;
    cout << "1) size()" << endl;
    cout << "2) addStart()" << endl;
    cout << "3) addEnd()" << endl;
    cout << "4) partString()" << endl;
    cout << "5) replPartString()" << endl;
    cout << "6) replWholeString()" << endl;
    cout << "7) compareString()" << endl;
    cout << "8) initString()" << endl;
    cout << "9) setString()" << endl;
    cout << "10) getString()" << endl;
    cout << "11) printStringScreen()" << endl;
    cout << "12) numericString()" << endl;
    cout << "13) alphabeticString()" << endl;
    cout << "0) Exit" << endl;
    cout << "-1 to Repeat options" << endl;

    // Switch statement user option selector
    do {
        // Collect user input for function selection
        cout << "Enter your choice: ";
        cin >> input;

        // If the input is not 0, execute the corresponding function
        if (input != 0) {
            if (input == 1) {
                // Declare variable
                myString mystring;

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "size()" << " | " << setw(20) << left << "nullvalue" << setw(1) << mystring.size() << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                cout << "Enter a string to be sized: "; // To user
                cin >> mystring; // From user

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string to be sized: " << mystring << endl;

                cout << "Size of string: " << mystring.size() << endl; // To user

                // Console report
                ofs << "Size of string: " << mystring.size() << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "size()" << " | " << setw(20) << left << mystring << setw(1) << mystring.size() << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == 2) {
                // Declare variables
                myString mystring, strToAdd;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter string to add to the start: "; // To user
                cin >> strToAdd; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "addStart()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "strToAdd (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter string to add to the start: " << strToAdd << endl;

                mystring.addStart(strToAdd); // Function call
                cout << "String after adding to the start: " << mystring << endl; // To user

                // Console report
                ofs << "String after adding to the start: " << mystring << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "addStart()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "strToAdd (Final)" << endl;
                ofs.close();
            }
            else if (input == 3) {
                // Declare variables
                myString mystring, strToAdd;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter string to add to the end: "; // To user
                cin >> strToAdd; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "addEnd()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "strToAdd (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter string to add to the end: " << strToAdd << endl;

                mystring.addEnd(strToAdd); // Function call
                cout << "String after adding to the end: " << mystring << endl; // To user

                // Console report
                ofs << "String after adding to the end: " << mystring << endl;
                ofs.close();


                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "addEnd()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "strToAdd (Final)" << endl;
                ofs.close();

            }
            else if (input == 4) {
                // Declare variables
                myString mystring;
                int startPos, length;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter a starting position: "; // To user
                cin >> startPos; // From user
                cout << "Enter length: "; // To user
                cin >> length;

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "partString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "startPos, length (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter a starting position: " << startPos << endl;
                ofs << "Enter length: " << length << endl;

                mystring.partString(startPos, length); // Function call
                cout << "Parted string: " << mystring << endl; // To user

                // Console report
                ofs << "Parted string: " << mystring << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "partString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "startPos, length (Final)" << endl;
                ofs.close();
            }
            else if (input == 5) {
                // Declare variables
                myString mystring, userstring;
                int startPos, length;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter a string to insert: "; // To user
                cin >> userstring; // From user
                cout << "Enter a starting position: "; // To user
                cin >> startPos; // From user
                cout << "Enter length: "; // To user
                cin >> length; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "replPartString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "userString, startPos, length (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter a string to insert: " << userstring << endl;
                ofs << "Enter a starting position: " << startPos << endl;
                ofs << "Enter length: " << length << endl;

                mystring.replPartString(userstring, startPos, length); // Function call
                cout << "Replaced parted string: " << mystring << endl; // To user

                // Console report
                ofs << "Replaced parted string: " << mystring << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "replPartString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "userString, startPos, length (Final)" << endl;
                ofs.close();
            }
            else if (input == 6) {
                // Declare variables
                myString mystring, userstring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter a string for replacement: "; // To user
                cin >> userstring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "replWholeString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "userString (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter a string for replacement: " << userstring << endl;

                mystring.replWholeString(userstring); // Function call
                cout << "Replaced user string: " << mystring << endl; // To user

                // Console report
                ofs << "Replaced user string: " << mystring << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "replWholeString()" << " | " << setw(21) << left << mystring << setw(1) << " | " << setw(20 + 1 + 19) << left << "userString (Final)" << endl;
                ofs.close();
            }
            else if (input == 7) {
                // Declare variables
                myString mystring, userstring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "Enter a string to compare: "; // To user
                cin >> userstring; // From user
                cout << "Matching indeces (- Alphabetically before | + Alphabetically after | 0 - Strings match)"; // To user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "compareString()" << " | " << setw(15) << left << mystring << " " << userstring << " | " << setw(20 + 1 + 19) << left << "userString (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "Enter a string to compare: " << userstring << endl;
                ofs << "Matching indeces (- Alphabetically before | + Alphabetically after | 0 - Strings match)" << endl;

                cout << endl << "Verdict: " << mystring.compareString(userstring) << endl; // To user

                // Console report
                ofs << "Verdict: " << mystring.compareString(userstring) << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "compareString()" << " | " << setw(21) << left << mystring.compareString(userstring) << setw(1) << " | " << setw(20 + 1 + 19) << left << "userString (Final)" << endl;
                ofs.close();
            }
            else if (input == 8) {
                // Declare variables
                myString mystring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "initString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;

                mystring.initString(); // Function call
                cout << "Initialized empty string: <" << mystring << ">" << endl; // To user

                // Console report
                ofs << "Initialized empty string: <" << mystring << ">" << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "initString()" << " | " << setw(21) << left << "nullvalue" << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == 9) {
                // Declare variables
                myString mystring;
                string userstring;

                cout << "Enter a string: "; // To user
                cin >> userstring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "setString()" << " | " << setw(21) << left << userstring << " | " << setw(20 + 1 + 19) << left << "userString (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << userstring << endl;

                mystring.setString(userstring); // Function call
                cout << "Converted user string: " << mystring << endl; // To user
                
                // Console report
                ofs << "Converted user string: " << mystring << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "setString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "userString (Final)" << endl;
                ofs.close();
            }
            else if (input == 10) {
                // Declare variables
                myString mystring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "getString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;

                cout << "String entered: " << mystring.getString() << endl; // To user

                // Console report
                ofs << "String entered: " << mystring.getString() << endl;
                ofs.close();

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "getString()" << " | " << setw(21) << left << mystring.getString() << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == 11) {
                // Declare variables
                myString mystring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user
                cout << "myString: "; // To user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "printStringScreen()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;
                ofs << "myString: " << mystring << endl;
                ofs.close();

                mystring.printStringScreen(); // Function call

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "printStringScreen()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == 12) {
                // Declare variables
                myString mystring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "numericString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;

                // Function return if/else
                if (mystring.numericString()) {
                    cout << "Input is an integer" << endl; // To user
                    ofs << "Input is an integer" << endl;
                    ofs.close();
                }
                else
                {
                    cout << "Input is real" << endl; // To user
                    ofs << "Input is real" << endl;
                    ofs.close();
                }

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "numericString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == 13) {
                // Declare variables
                myString mystring;

                cout << "Enter a string: "; // To user
                cin >> mystring; // From user

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "alphabeticString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Original)" << endl;
                ofs.close();

                // Console report
                ofs.open("console.txt", ios::app);
                ofs << "Enter a string: " << mystring << endl;

                // Function return if else
                if (mystring.alphabeticString()) {
                    cout << "Input is alphabetic" << endl; // To user
                    ofs << "Input is alphabetic" << endl;
                    ofs.close();
                }
                else {
                    cout << "Input is not alphabetic" << endl; // To user
                    ofs << "Input is not alphabetic" << endl;
                    ofs.close();
                }

                // Log report
                ofs.open("log.txt", ios::app);
                ofs << setw(20) << left << "alphabeticString()" << " | " << setw(21) << left << mystring << " | " << setw(20 + 1 + 19) << left << "No_Params (Final)" << endl;
                ofs.close();
            }
            else if (input == -1) {
                cout << "Welcome to the myString class" << endl;
                cout << "1) size()" << endl;
                cout << "2) addStart()" << endl;
                cout << "3) addEnd()" << endl;
                cout << "4) partString()" << endl;
                cout << "5) replPartString()" << endl;
                cout << "6) replWholeString()" << endl;
                cout << "7) compareString()" << endl;
                cout << "8) initString()" << endl;
                cout << "9) setString()" << endl;
                cout << "10) getString()" << endl;
                cout << "11) printStringScreen()" << endl;
                cout << "12) numericString()" << endl;
                cout << "13) alphabeticString()" << endl;
                cout << "0) Exit" << endl;
                cout << "-1 to Repeat options" << endl;
            }
            else {
                cout << "Invalid choice" << endl;
            }
        }
    } while (input != 0);

    ofs.close();

    system("pause");
    return 0;
}
