/*
ID: xi-lin2
LANG: C++
PROG: milk
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair <int, int> val1, pair <int, int> val2)
{
	return val1.first < val2.first;
}

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int N,M,price,amount,sum = 0;
	vector < pair <int, int> >  vec;
	fin >> N >> M;

	for(int i = 0; i < M; i++ )
	{
		fin >> price >> amount;
		vec.push_back(make_pair <int,int> (price, amount));
	}
	sort(vec.begin(), vec.end(), cmp);
	vector < pair <int, int> > :: iterator iter;
	for(iter = vec.begin(); iter != vec.end(); iter++)
	{
		if((*iter).second < N) {
			sum += (*iter).second * (*iter).first;
			N -= (*iter).second;
		} else {
			sum += (*iter).first * N;
			break;
		}
	}

	fout << sum << endl;
	return 0;
}
