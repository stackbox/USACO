/*
ID: xi-lin2
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	vector <string> order;
	map <string, int> lists;


	ifstream  fin("gift1.in");
	ofstream  fout("gift1.out");

	int NP;

	string giver,receiver;
	fin >> NP;
	for(int i = 0; i < NP; i++)
	{
		string tmp;
		fin >> tmp;
		lists.insert(map <string, int>::value_type(tmp,0));
		order.push_back(tmp);
	}

	while(fin >> giver)
	{
		
		int money,numbers;
		fin >> money >> numbers;
		for(int i = 0; i < numbers; i++)
		{
			fin >> receiver;
			lists[receiver] += money / numbers;
		}
		if(numbers != 0)
			lists[giver] -= (money - money%numbers);
	}

	for(vector <string>::iterator iter = order.begin(); iter != order.end() ; iter++)
	{
		fout << *iter << " " << lists[*iter] << endl;
	}






	return 0;
}
