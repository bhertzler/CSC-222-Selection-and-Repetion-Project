// CSC 222 Selection and Repetion Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Benjamin Hertzler
// Selection and Repetion Programming Project
// Program 1: Calculator

// Description: This program takes two operations and a +, -, *, / operator and outputs the result. Enter q to quit.
// Required User Input: 2 integers and an operator, or q to quit.
// Program Output: The result of the desired operation.
// Supplied Constants: The 4 available operators (+, -, *, /).

#include <iostream>
#include <exception>
using namespace std;

int main()
{
    char input, operation;
    int x, y;

	cout << "Calculator: Enter 2 integers and a 4 function operator or 'q' to quit." << endl << endl;
	try
	{
		while (true)
		{
			cin >> input;
			if (tolower(input) != 'q')
			{
				if (isdigit(input))
					x = input - '0';
				else
					throw domain_error("Invalid Operand");
			}
			else
				break;
			cin >> operation >> input;
			if (isdigit(input))
				y = input - '0';
			else
				throw domain_error("Invalid Operand");
			switch (operation)
			{
			case '+':
				cout << " = " << x + y << endl;
				break;
			case '-':
				cout << " = " << x - y << endl;
				break;
			case '*':
				cout << " = " << x * y << endl;
				break;
			case '/':
				cout << " = " << x / y << endl;
				break;
			default:
				throw domain_error("Invalid Operator");
				break;
			}
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

