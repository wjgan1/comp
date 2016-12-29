/*
ID: wgan8561
PROG: holstein
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
#include <queue>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "holstein.in"
#define out1 "data.out"
#define out2 "holstein.out"

#define MAX_V 25
#define MAX_G 15

int V, G, v[MAX_V], current_v[MAX_V];
int M = 1 << 30, MS = 1 << 30, S[MAX_G], s[MAX_G];
vector<pair<int,vector<int> > > g;
vector<int> C;
int asdf = 0;

void process(vector<int>)
{
	for (int i = 0; i < V; ++i)
		current_v[i] = 0;

	for (int i = 0; i < G; ++i)
		s[i] = 0;

	int ms = 0;
	for (int i = 0; i < C.size(); ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			current_v[j] += g[C[i]-1].second[j];
		}
		ms += g[C[i]-1].first;
		if (s[C[i]-1] != 0)
			return;
		++s[C[i]-1];
	}

	for (int i = 0; i < V; ++i)
		if (current_v[i] < v[i])
			return;

	if (C.size() < M || (C.size() == M && ms < MS))
	{
		M = C.size();
		MS = ms;
		for (int i = 0; i < G; ++i)
			S[i] = s[i];
	}
}

void dfs(int depth, int index, int max_depth)
{
	//cout << depth << " " << index << endl;
	//if (asdf > 40000)
		//return;
	if (depth == max_depth)
	{
		process(C);
		return;
	}
	for (int i = index; i < G; ++i)
	{
		++asdf;
		C[depth] = i+1;
		dfs(depth+1, i+1, max_depth);
		C[depth] = 0;
	}
}

int main()
{
	ifstream fin(in2);
	fin >> V;
	for (int i = 0; i < V; ++i)
	{
		fin >> v[i];
	}
	fin >> G;
	g.resize(G);
	for (int i = 0; i < G; ++i)
	{
		int SUM = 0;
		for (int j = 0; j < V; ++j)
		{
			int N;
			fin >> N;
			g[i].second.push_back(N);
			SUM += N;
		}
		g[i].first = SUM;
	}
	fin.close();

	//sort(g.begin(),g.end());

	int D = 1;
	while (asdf < 100000 && M == 1 << 30 && D <= G)
	{
		C.resize(D);
		dfs(0,0,D);
		//cout << D << " " << asdf << endl;
		++D;
	}
	
	ofstream fout(out2);
	fout << M;
	for (int i = 0; i < G; ++i)
	{
		//cout << S[i] << " ";
		for (int j = 0; j < S[i]; ++j)
		{
			fout << " " << i+1;
		}
	}
	//cout << MS << " " << MS2 << endl;
	//cout << endl;
	fout << endl;
	fout.close();

	return 0;
}