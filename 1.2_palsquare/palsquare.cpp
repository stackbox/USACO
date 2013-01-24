/*
ID: xi-lin2
LANG: C++
PROG: palsquare
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const char characters[] = "0123456789ABCDEFGHIJ";
int base;

bool isPal(int N , string &ans)
{
	string tmp;
	for(; N; tmp.push_back(characters[N%base]), N /= base)
		;
	string tmp2(tmp);
	reverse(tmp2.begin(),tmp2.end());
	ans = tmp2;
	
	if(tmp2 == tmp) 
		return true;
	
	return false;
}

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	fin >> base;
	string  inher,ans;
	
	for(int i = 1; i <= 300; i++)
	{
		if(isPal(i*i,ans))	
		{
			isPal(i,inher);
			fout << inher << " " << ans << endl;
		}
			
	}
	
	return 0;
}
