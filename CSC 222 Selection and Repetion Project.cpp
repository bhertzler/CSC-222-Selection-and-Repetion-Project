// CSC 222 Selection and Repetion Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Benjamin Hertzler
// Selection and Repetion Programming Project
// Program 2: Calculator, Part 2

// Description: This program takes two operations and a +, -, *, / operator and outputs the result. Enter q to quit.
// Required User Input: 2 integers and an operator, or q to quit.
// Program Output: The result of the desired operation.
// Supplied Constants: The 4 available operators (+, -, *, /).

#include <string>
#include <iostream>
#include <exception>
using namespace std;

int main()
{
	string input;
	char sentinel, operation;
    double x, y;

	cout << "Calculator: Enter 2 integers and a 4 function operator or 'q' to quit." << endl << endl;
	try
	{
		while (true)
		{
			cin >> input;
			sentinel = input[0];
			if (tolower(sentinel) != 'q')
			{
				x = stod(input);
			}
			else
				break;
			cin >> operation >> input;
			y = stod(input);
			if (operation == '+')
				cout << " = " << x + y << endl;
			else if (operation == '-')
				cout << " = " << x - y << endl;
			else if (operation == '*')
				cout << " = " << x * y << endl;
			else if (operation == '/')
				cout << " = " << x / y << endl;
			else
				throw domain_error("Invalid Operator");
		}
	}
	catch (const exception& err)
	{
		cout << "ERROR: " << err.what() << endl;
	}
	catch (...)
	{
		cout << "ERROR: Invalid Input" << endl;
	}
}

