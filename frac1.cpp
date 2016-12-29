/*
ID: wgan8561
PROG: frac1
LANG: C++
*/

//foreverbronze
//problem link
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "frac1.in"
#define out1 "data.out"
#define out2 "frac1.out"

int N;
vector< pair<double,pair<int,int> > > V;

int main()
{
	ifstream fin(in2);
	fin >> N;
	fin.close();

	for(int i = 0; i <= N; ++i)
		for (int j = 0; j <= i; ++j)
			V.push_back(make_pair(j*1.0/i,make_pair(j,i)));

	sort(V.begin(),V.end());
	
	ofstream fout(out2);
	for (int i = 1; i < V.size(); ++i)
		if ( V[i].first != V[i-1].first)
			fout << V[i].second.first << "/" << V[i].second.second << endl;
	fout.close();

	return 0;
}