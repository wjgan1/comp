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
#define in2 "planting.in"
#define out1 "data.out"
#define out2 "planting.out"

#define m_n 10

vector<int> x, y;
pair<pair<int,int>,pair<int,int> > g[m_n];
int n, farm[2*m_n][2*m_n];

int findx(int val)
{
	for (int i = 0; i < x.size(); ++i)
		if (x[i] == val)
			return i;
	return -1;
}

int findy(int val)
{
	for (int i = 0; i < y.size(); ++i)
		if (y[i] == val)
			return i;
	return -1;
}

int main()
{
	ifstream fin(in1);
	fin >> n;
	x.resize(2*n);
	y.resize(2*n);
	for (int i = 0; i < n; ++i)
	{
		fin >> g[i].first.first >> g[i].second.second >> g[i].first.second >> g[i].second.first;
		x[i] = g[i].first.first;
		x[2*n-1-i] = g[i].first.second;
		y[i] = g[i].second.first;
		y[2*n-1-i] = g[i].second.second;
	}
	fin.close();

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	for (int i = 0; i < x.size()-1; ++i)
	{
		if(x[i] == x[i+1])
		{
			x.erase(x.begin()+i);
			--i;
		}
	}

	for (int i = 0; i < y.size()-1; ++i)
	{
		if(y[i] == y[i+1])
		{
			y.erase(y.begin()+i);
			--i;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int a = findx(g[i].first.first);
		int b = findx(g[i].first.second);
		int c = findy(g[i].second.first);
		int d = findy(g[i].second.second);
		for (int j = a; j < b; ++j)
			for (int k = c; k < d; ++k)
				farm[j][k] = 1; 
	}

	for (int i = 0; i < y.size(); ++i)
	{
		for(int j = 0; j < x.size(); ++j)
			cout << farm[j][i] << " ";
		cout << endl;
	}

	int ans = 0;
	for (int i = 0; i < x.size(); ++i)
		for (int j = 0; j < y.size(); ++j)
			if (farm[i][j] == 1)
				ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
	
	ofstream fout(out1);
	fout << ans << endl;
	fout.close();

	return 0;
}