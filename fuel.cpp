#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define in1 "_data.in"
#define in2 "fuel.in"
#define out1 "_data.out"
#define out2 "fuel.out"

int n, g, b, d;
set<int> path;
vector<pair<int,int> > station;
set<pair<int,int> > poss_station;

int min_cost(int fuel, int st, int fn)
{
	if (station[fn].first-station[st].first <= fuel)
		return station[st].second*(station[fn].first-station[st].first);
	int min = 1 << 30;
	int min_i;
	for (int i = st; i <= fn; ++i)
		if (station[i].first < min)
		{
			min = station[i].first;
			min_i = i;
		}
	return min_cost(fuel,st,min_i-1)+min_cost(g,min_i+1,fn);
}

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n >> g >> b >> d;
	station.resize(n+1);
	for (int i = 0; i < n; ++i)
		fin >> station[i].first >> station[i].second;
	station[n].first = d;
	station[n].second = 0;
	sort(station.begin(),station.end());

	fout << min_cost(b,0,n) << endl;

	fin.close();
	fout.close();

	return 0;
}