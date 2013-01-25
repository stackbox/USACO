/*
ID: xi-lin2
LANG: C++
PROG: barn1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int tags[202],M,S,C;

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	fin >> M >> S >> C;
	for(int i = 0; i < 202; i++)
		tags[i] = 0;
	for(int i = 0; i < C; i++)
	{
		int tmp;
		fin >> tmp;
		tags[tmp] = 1;
	}

	vector <int> tmpVec;

	int startPos = -1,endPos;
	for(int i = 0; i < 202; i++)
	{
		if(startPos == -1 && tags[i] == 1) startPos = i;
		if(tags[i] == 1) endPos = i;
	}

	int tmpLength = 0;
	for(int i = startPos ; i <= endPos; i++)
	{
		if(tags[i] == 0) tmpLength++;
		else {
			if(tmpLength != 0) tmpVec.push_back(tmpLength);
			tmpLength = 0;
		}
	}
	
	cout << startPos << " " << endPos << endl;
	
	sort(tmpVec.begin(), tmpVec.end(), greater<int>());
	
	for(vector <int> ::iterator iter = tmpVec.begin(); iter != tmpVec.end(); iter++)
		cout << *iter << endl;

	int sum = endPos - startPos + 1;

	for(int i = 0; i < M - 1; i++)
	{
		if(i == tmpVec.size()) break;
		sum -= tmpVec[i];
	}
		
	fout << sum << endl;
	return 0;
}
