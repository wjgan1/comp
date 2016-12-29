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
#define in2 "cruise.in"
#define out1 "_data.out"
#define out2 "cruise.out"

int n, m;
long long k;
int dir[500], ptnr[1001][2];
long long t[1001];
int ans;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		fin >> ptnr[i+1][0] >> ptnr[i+1][1];
	for (int i = 0; i < m; ++i)
	{
		char c;
		fin >> c;
		dir[i] = c == 'L' ? 0 : 1;
	}

	int loc = 1;
	for (long long i = 1; i <= k; ++i)
	{
		for (int j = 0; j < m; ++j)
			loc = ptnr[loc][dir[j]];
		if (t[loc] == 0)
			t[loc] = i;
		else
		{
			int val = (k-t[loc])%(i-t[loc])+t[loc];
			for (int i = 1; i <= n; ++i)
				if (t[i] == val)
				{
					ans = i;
					break;
				}
			break;
		}
	}

	if (ans == 0)
		ans = loc;

	fout << ans << endl;

	fin.close();
	fout.close();

	return 0;
}	