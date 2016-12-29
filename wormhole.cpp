/*
ID: wgan8561
PROG: wormhole
LANG: C++
*/

//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=360
//2/12/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "wormhole.in"
#define out1 "data.out"
#define out2 "wormhole.out"

#define MAX_N 12

int N, ans, P[MAX_N+1], R[MAX_N];
vector< pair<int,int> > V;

void check()
{
	for (int i = 1; i <= N; ++i)
	{
		int j = 0;
		int k = i;
		for (j = 0; j <= N; ++j)
		{
			if (R[P[k]-1] == -1)
				break;
			else
				k = R[P[k]-1]+1;
		}
		if (j > N)
		{
			/*
			for (int i = 1; i <= N; ++i)
			{
				cout << i << "-" << P[i] << " ";
			}
			*/
			//cout << endl;
			++ans;
			return;
		}
	}
}

void compute()
{
	int i;
	for (i = 1; i <= N; ++i)
		if (P[i] == 0)
			break;

	if (i > N)
	{
		check();
		return;
	}

	for (int j = i+1; j <= N; ++j)
	{
		if (P[j] == 0)
		{
			P[i] = j;
			P[j] = i;
			compute();
			P[i] = P[j] = 0;
		}
	}

}

int main()
{
	ifstream fin(in2);
	fin >> N;
	V.resize(N);
	for (int i = 0; i < N; ++i)
	{
		fin >> V[i].second >> V[i].first;
	}
	fin.close();

	sort(V.begin(),V.end());

	for (int i = 0; i < N; ++i)
		if (V[i].first == V[i+1].first)
			R[i] = i+1;
		else
			R[i] = -1;
	R[N-1] = -1;
	/*
	for (int i = 0; i < N; ++i)
	{
		if (R[i] != -1)
		cout << V[i].second << " " << V[i].first << " " << V[R[i]].second << " " << V[R[i]].first << endl;
	}
	*/
	compute();

	ofstream fout(out2);
	fout << ans << endl;
	fout.close();

	return 0;
}