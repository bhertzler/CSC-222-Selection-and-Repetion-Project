// CSC 222 Selection and Repetion Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Benjamin Hertzler
// Selection and Repetion Programming Project
// Merge Files

// Program Description: This program combines the data from two files into a single file.
// Required User Input: None.
// Program Output: An output file.
// Supplied Constants: Two input files

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

#define FILE_NAME_1 "file1.txt"
#define FILE_NAME_2 "file2.txt"
#define OUT_FILE_NAME "output.txt"
#define MAX_LENGTH 100
#define MAX_OUTPUT_LENGTH 200

// Function to read a file into an array.
// Preconditons:	string fileName is a file that exists.
//		string lines[] is an empty array of size max_lines.
//		int max_lines should be smaller than the number of lines in the file.
// Postconditions:	The contents of the file will be read into lines[].
//					The length of the file will return in int length.
//		
void readFile(string fileName, string lines[], int max_lines, int& len);

// Function to combine two alphabetically sorted lists into one alphabetically sorted list.
// Preconditions:	a_arr[] and b_arr[] must be an alphabetically sorted string arrays.
//		a_len and b_len must be the lengths of a_arr and b_arr respectively.
//		rtn_max must be the size of rtn_arr.
// Postconditions:	populates rtn_len with the alphabetically sorted combination of a_arr and b_arr.
//		stores the length of rtn_arr in rtn_len.
//
void concatSort(string a_arr[], string b_arr[], string rtn_arr[], int a_len, int b_len, int rtn_max, int& rtn_len);

// Function to write a file from an array.
// Precondition:	string fileName is a valid file name.
//		int length is the length of lines[].
// Postcondition:	Outputs lines in file fileName.
//
void writeFile(string fileName, string lines[], int len);

int main()
{
	int len_f1, len_f2, output_len;
	string file_1[MAX_LENGTH], file_2[MAX_LENGTH], out_file[MAX_OUTPUT_LENGTH];

	readFile(FILE_NAME_1, file_1, MAX_LENGTH, len_f1);
	readFile(FILE_NAME_2, file_2, MAX_LENGTH, len_f2);

	concatSort(file_1, file_2, out_file, len_f1, len_f2, MAX_OUTPUT_LENGTH, output_len);
	writeFile(OUT_FILE_NAME, out_file, output_len);
}

void readFile(string fileName, string lines[], int max_lines, int& len)
{
	try
	{
		ifstream f(fileName);
		if (f.is_open())
		{
			string line;
			int i = 0;
			while (getline(f, line) && i < max_lines)
			{
				lines[i] = line;
				i++;
			}
			len = i;
			f.close();
		}
		else
			throw runtime_error("Invalid File");
	}
	catch (const exception& err)
	{
		cout << "ERROR: " << err.what() << endl;
	}
}

void concatSort(string a_arr[], string b_arr[], string rtn_arr[], int a_len, int b_len, int rtn_max, int& rtn_len)
{
	int i = 0, a = 0, b = 0;
	while (a < a_len && b < b_len && i < rtn_max)
	{
		if (a_arr[a] <= b_arr[b])
		{
			rtn_arr[i] = a_arr[a];
			i++;
			a++;
		}
		else
		{
			rtn_arr[i] = b_arr[b];
			i++;
			b++;
		}
	}
	if (a < a_len)
	{
		for (a; a < a_len; a++)
		{
			if (i < rtn_max)
			{
				rtn_arr[i] = a_arr[a];
				i++;
			}
			else
				break;
		}
	}
	else if (b < b_len)
	{
		for (b; b < b_len; b++)
		{
			if (i < rtn_max)
			{
				rtn_arr[i] = a_arr[a];
				i++;
			}
			else
				break;
		}
	}
	rtn_len = i;
}

void writeFile(string fileName, string lines[], int len)
{
	ofstream f(fileName);
	for (int i = 0; i < len; i++)
	{
		f << lines[i] << endl;
	}
	f.close();
}

