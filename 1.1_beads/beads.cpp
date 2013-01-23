/*
ID: xi-lin2
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


string  getNewStr(string &s,const int pos)
{
	string tmp1 =  s.substr(pos) + s.substr(0,pos);
	return  (tmp1 + tmp1);
}

int countBeads(string &s, int N)
{
	int leftCount=0,rightCount=0,i,j,k;
	char tag = 'w';
	int prePos = N;
	while(1)
	{
		if(s[prePos] != tag && tag != 'w' && s[prePos] != 'w' || prePos == 2*N) break;
		else if(s[prePos] == 'w') prePos++,rightCount++;
		else tag = s[prePos],prePos++,rightCount++;
	}
	
	prePos = N-1;
	tag = 'w';
	while(1)
	{
		if(s[prePos] != tag && tag != 'w' && s[prePos] != 'w' || prePos < 0 ) break;
		else if(s[prePos] == 'w') prePos--,leftCount++;
		else tag = s[prePos],prePos--,leftCount++;
	}
	
	if(rightCount + leftCount > N) return N;
	else return (rightCount + leftCount);
	
}
int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
	string str;
	int N,maxVal = -1;
	fin >> N >> str;
	for(int i = 0; i < N; i++)
	{
		string temp = getNewStr(str,i);
		int tempCount = countBeads(temp,N);
		if(tempCount > maxVal) maxVal = tempCount;
	}
	
	fout << maxVal << endl;
	
	return 0;
}
