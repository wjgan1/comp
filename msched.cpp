//foreverbronze

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
#define in2 "msched.in"
#define out1 "_data.out"
#define out2 "msched.out"

int n, m;
int ti[10000];
vector<set<int> > edg;
int ans, maxdist[10000];

int dfs(int src)
{
	if (maxdist[src] != 0)
		return maxdist[src];
	for (set<int>::iterator it = edg[src].begin(); it != edg[src].end(); ++it)
	{
		int dist = dfs(*it);
		if (dist > maxdist[src])
			maxdist[src] = dist;
	}
	maxdist[src] += ti[src];
	return maxdist[src];
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> m;
	for (int i = 0; i < n; ++i)
		fin >> ti[i];

	edg.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int bf, af;
		fin >> bf >> af;
		//cout << bf << " " << af << endl;
		edg[bf-1].insert(af-1);
		//cout << bf << " " << af << endl;
	}

	for (int i = 0; i < n; ++i)
		ans = max(dfs(i),ans);

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}