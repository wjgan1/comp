//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=432
//1/27/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "decorate.in"
#define out1 "data.out"
#define out2 "decorate.out"
#define MAXN 50000
#define MAXM 100000

int N, M;
int F, J;
vector< vector<int> > v;
int arr[MAXN];
bool impos = false;

void dfs(int a, bool FJ) //FJ means parent was 1 or F, !FJ means parents was -1 or J
{
	if (impos)
		return;
	if (FJ)
	{
		arr[a] = 1;
		++F;
	}
	else
	{
		arr[a] = -1;
		++J;
	}

	for (int i = 0; i < v[a].size(); ++i)
	{
		if (arr[v[a][i]] == 0)
		{
			dfs(v[a][i],!FJ);
		}
		else if (arr[v[a][i]] == arr[a])
		{
			cout << a+1 << " " << v[a][i]+1 << endl;
			impos = true;
			return;
		}
	}
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> N >> M;
	v.resize(N);

	for (int i = 0; i < 2*M; i +=2)
	{
		int a, b;
		fin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] == 0 && !impos)
		{
			dfs(i,true);
			ans += max(F,J);
			F = J = 0;
		}
	}
	
	ans = impos ? -1 : ans;
	fout << ans << endl;

	fin.close();
	fout.close();

	return 0;
}