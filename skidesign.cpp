/*
ID: wgan8561
PROG: skidesign
LANG: C++
*/

//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=376
//2/13/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "skidesign.in"
#define out1 "data.out"
#define out2 "skidesign.out"

#define MAX 1 << 30
#define MAX_E 101
#define RANGE 18

int N, E[MAX_E];

int main()
{
	ifstream fin(in2);
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		int e;
		fin >> e;
		++E[e];
	}
	fin.close();
	
	int cost = 0;
	int ans = MAX;
	for (int i = 0; i < MAX_E-RANGE; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cost += E[j]*(j-i)*(j-i);
		}
		for (int j = i+RANGE; j < MAX_E; ++j)
		{
			cost += E[j]*(j-(i+RANGE-1))*(j-(i+RANGE-1));
		}
		if (cost < ans)
		{
			ans = cost;
		}
		cost = 0;
	}

	ofstream fout(out2);
	fout << ans << endl;
	fout.close();

	return 0;
}