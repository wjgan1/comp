/*
ID: wgan8561
PROG: lamps
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
#define in2 "lamps.in"
#define out1 "data.out"
#define out2 "lamps.out"

int n, c;
int cs[100], fs[100];
int m[4][105]; 
vector<vector<int> > sol;
int s = 0;
ifstream fin(in2);
ofstream fout(out2);

void check()
{
	//cout << "yo" << endl;
	bool b = true;
	for (int i = 0; i < n; ++i)
	{
		if (fs[i] != 0 && fs[i] != cs[i] && fs[i] != cs[i]-1)
		{
			b = false;
			break;
		}
	}

	if (b)
	{
		for (int i = 0; i < n; ++i)
			sol[s].push_back(cs[i]);
		++s;
	}
}

void solve(int t, int d) //the button to press, how many buttons have been pressed
{
	if (d >= c)
	{
		check();
		return;
	}
	if (t > 3)
	{
		check();
		return;
	}
	solve(t+1,d);	
	for (int i = 0; i < n; ++i)
		cs[i] = (cs[i]+m[t][i])%2;
	solve(t+1,d+1);
	for (int i = 0; i < n; ++i)
		cs[i] = (cs[i]+m[t][i])%2;
}

int main()
{
	fin >> n >> c;
	int in;
	fin >> in;
	sol.resize(17);
	while (in != -1)
	{
		fs[in-1] = 1;
		fin >> in;
	}
	fin >> in;
	while (in != -1)
	{
		fs[in-1] = -1;
		fin >> in;
	}
	for (int i = 0; i < n; ++i)
		cs[i] = m[0][i] = 1;
	for (int i = 0; i < n; i+=2)
		m[1][i] = m[2][i+1] = 1;
	for (int i = 0; i < n; i+=3)
		m[3][i] = 1;


	
	solve(0,0);

	sort(sol.begin(),sol.end());

	for (int i = 17-s; i < 17; ++i)
	{
		if (!operator==(sol[i],sol[i-1]))
		{
			for (int j = 0; j < n; ++j)
				fout << sol[i][j];
			fout << endl;
		}
	}

	if (s == 0)
		fout << "IMPOSSIBLE" << endl;

	fin.close();
	fout.close();

	return 0;
}