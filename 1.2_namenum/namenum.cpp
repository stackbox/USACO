/*
ID: xi-lin2
LANG: C++
PROG: namenum
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string input;

const char characters[] = "22233344455566670778889990";

bool isValid(string str)
{
	if(input.length() != str.length()) return false;

	string tempStr;
	for(int i = 0; i < str.length(); i++)
	{
		tempStr.push_back( characters[str[i] - 'A']);
	}
	if(tempStr == input) return true;
	return false;
}

int main()
{
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	ofstream fout("namenum.out");

	fin >> input;
	string tmp;
	bool tag = false;
	
	while(dict >> tmp)
	{
		if(isValid(tmp))
		{
			tag = true;
			fout << tmp << endl;
		}
	}
	
	
	isValid("KRISTOPHER");
	if(tag == false) fout << "NONE" << endl;
	return 0;
}
