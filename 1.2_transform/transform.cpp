/*
ID: xi-lin2
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using  namespace  std;

vector <string>  before, after;
int N;

void initData( vector < string > & vec , ifstream &input)
{
	string tmp;
	for(int i = 0; i < N; i++)
	{
		input >> tmp;
		vec.push_back(tmp);
	}
}

bool isEqual(vector < string > &vec1, vector <string> &vec2)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			if(vec1[i][j] != vec2[i][j]) return false;
	}
	return true;
}

void rotateSquare( vector < string > &vec1, vector < string > &vec2, int choose)
{
	
	switch(choose)
	{
		case 1:
		{
			for(int i = 0; i < N; i++)
			{
				string  tmp;
				for(int j = N - 1; j >= 0; j--)
					tmp.push_back(vec1[j][i]);
				vec2.push_back(tmp);
			}
			break;
		}

		case 2:
		{
			for(int i = N - 1; i >= 0; i--)
			{
				string tmp = vec1[i];
				reverse(tmp.begin(), tmp.end());
				vec2.push_back(tmp);
			}
			break;
		}

		case 3:
		{
			
			for(int i = N - 1; i >= 0; i--)
			{
				string tmp;
				for(int j = 0; j < N; j++)
					tmp.push_back(vec1[j][i]);
				vec2.push_back(tmp);
			}
			break;
		}

		case 4:
		{
			for(int i = 0; i < N; i++)
			{
				string tmp = vec1[i];
				reverse(tmp.begin(), tmp.end());
				vec2.push_back(tmp);
			}
			break;
		}
	}
}

int startCompute()
{
	for(int i = 1; i <= 4; i++)
	{
		vector <string> tmpVec;
		rotateSquare(before,tmpVec,i);
		if(isEqual(tmpVec, after)) return i;
	}

	vector <string> tmpBefore;
	rotateSquare(before, tmpBefore,4);

	for(int i = 1; i <=3; i++)
	{
		vector <string> tmpVec;
		rotateSquare(tmpBefore, tmpVec,i);
		if(isEqual(tmpVec,after)) return 5;
	}

	if(isEqual(before, after)) return 6;
	return 7;
}


int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	
	fin >> N;
	
	initData(before,fin);
	initData(after,fin);

	fout << startCompute() << endl;

	return 0;
}
