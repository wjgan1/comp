//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define in1 "data.in"
#define in2 "superbull.in"
#define out1 "data.out"
#define out2 "superbull.out"

int n, val[2000];
int dist[2000];
bool intree[2000];

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;
	for (int i = 0; i < n; intree[i] = false, ++i)
		fin >> val[i];

	int c = 0;
	long ans = 0;
	dist[c] = 0;
	for (int i = 0; i < n; ++i)
	{
		intree[c] = true;
		ans += dist[c];
		for (int j = 0; j < n; ++j)
			if ((val[j]^val[c]) > dist[j])
				dist[j] = val[j]^val[c];
		c = -1;
		for (int j = 0; j < n; ++j)
			if (!intree[j] && (c == -1 || dist[j] > dist[c]))
				c = j;
	}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}