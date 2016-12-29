/*
ID: wgan8561
PROG: concom
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
#include <queue>

using namespace std;

#define in1 "data.in"
#define in2 "concom.in"
#define out1 "data.out"
#define out2 "concom.out"

int n, o[101][101];
int own[101];
queue<int> q;
vector<pair<int,int> > ans;
vector<vector<int > > adj;

void ff(int a)
{
	for (int j = 1; j <= 100; ++j)
		if (o[a][j] <= 50)
			own[j] = o[a][j];

	for (int i = 0; i < q.size(); )
	{
		int c = q.front();
		if (a != c)
			ans.push_back(make_pair(a,c));
		own[c] = -1;
		q.pop();
		for (int j = 1; j <= 100; ++j)
		{
			if (own[j] != -1)
				own[j] += o[c][j];
			//if (a == 34)
			//	cout << c << " " << own[j] << endl;
			if (own[j] > 50)
			{
				own[j] = -1;
				q.push(j);
			}
		}
		//cout << endl;
	}
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;

	adj.resize(101);
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		fin >> a >> b >> c;
		o[a][b] = c;
		if (c > 50)
			adj[a].push_back(b);
	}

	for (int i = 1; i <= 100; ++i)
	{
		if (adj[i].size() > 0)
		{
			//cout << i << endl;
			for (int j = 0; j <= 100; ++j)
				own[j] = 0;
			for (int j = 0; j < adj[i].size(); ++j)
				q.push(adj[i][j]);
			ff(i);
		}
	}

	sort(ans.begin(),ans.end());

	for (int i = 0; i < ans.size(); ++i)
		fout << ans[i].first << " " << ans[i].second << endl;

	fin.close();
	fout.close();

	return 0;
}