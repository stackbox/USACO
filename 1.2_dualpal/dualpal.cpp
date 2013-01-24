/*
ID: xi-lin2
LANG: C++
PROG: dualpal
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const char code[] = "0123456789";

bool Check(int x)
{
	int ans = 0;
	int xtemp = x;   //important:每次循环会改变x，须每次进行初始化

	for(int base = 2; base <= 10; base++)
	{
		string num;
		x = xtemp;
		for( ; x; num.push_back(code[x%base]),x /= base)
			;

		if(num[0] == '0') continue;

		string nump(num);
		reverse(num.begin(),num.end());
		if(num == nump) ans ++;
		
		if(ans >= 2) return true;

	}

	return false;

}

int main()
{
	
	ifstream fin  ("dualpal.in" );
	ofstream fout ("dualpal.out");

	int N,S,i,count = 0;
	fin >> N >> S;
	for(i = S+1; ;i++)
	{
		if(count == N) break;

		if(Check(i)) 
		{
			fout << i << endl;
			count ++;
		}
	}
	return 0;
}
