/*
ID: xi-lin2
LANG: C++
PROG: milk2
*/

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXLEN 5002
using namespace std;

struct Interval
{
	int start;
	int end;
};

bool cmp(Interval a, Interval b)
{
	if(a.start < b.start) return true;
	else if (a.start == b.start && a.end < b.end) return true;
	return false;
}

int main()
{
	Interval list[MAXLEN];
	int N,start,end;
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	fin >> N;
	for(int i = 0; i < N; i++)
	{
		fin >> start >> end;
		list[i].start = start;
		list[i].end = end;
	}

	sort(list,list+N,cmp);
	

	for(int i = 0; i < N ; i++)
	{
		if(list[i].end >= list[i+1].start) {
			if(list[i].end <= list[i+1].end)  list[i].end = list[i+1].end;
			else list[i+1].end = list[i].end;  //important
		list[i+1].start = list[i].start;
		}
	}

	int val1 = 0,val2 = 0;

	for(int i = 0; i < N ; i++) 
	{
		if(list[i].end - list[i].start > val1) 
		{
			val1 = list[i].end - list[i].start;
		}
		if(list[i].end < list[i+1].start && list[i+1].start - list[i].end > val2) val2 = list[i+1].start - list[i].end;

	}

	fout << val1 << " " << val2 << endl;
	return 0;
}
