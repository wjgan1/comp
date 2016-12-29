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
#define in2 "cowrun.in"
#define out1 "_data.out"
#define out2 "cowrun.out"

int n;
int loc[1000];
long long dp[1000][1000][2];
long long t[1000][1000][2];

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n;
	for (int i = 0; i < n; ++i)
		fin >> loc[i];
	sort(loc,loc+n);

	for (int i = 0; i < n; ++i)
		dp[i][i][0] = dp[i][i][1] = t[i][i][0] = t[i][i][1] = abs(loc[i]-0);
	for (int k = 1; k < n; ++k)
	{
		for (int i = 0; i < n-k; ++i)
		{
			int j = i+k;
			dp[i][j][0] = dp[i][j][1] = 1LL << 60;
			int cost = dp[i+1][j][0]+t[i+1][j][0]+abs(loc[i+1]-loc[i]);
			if (cost < dp[i][j][0])
			{
				dp[i][j][0] = cost;
				t[i][j][0] = t[i+1][j][0]+abs(loc[i+1]-loc[i]);
			}
			cost = dp[i+1][j][1]+t[i+1][j][1]+abs(loc[j]-loc[i]);
			if (cost < dp[i][j][0] || (cost == dp[i][j][0] && t[i][j][1]+abs(loc[j]-loc[i]) < t[i][j][0]))
			{
				dp[i][j][0] = cost;
				t[i][j][0] = t[i+1][j][1]+abs(loc[j]-loc[i]);
			}
			cost = dp[i][j-1][1]+t[i][j-1][1]+abs(loc[j]-loc[j-1]);
			if (cost < dp[i][j][1])
			{
				dp[i][j][1] = cost;
				t[i][j][1] = t[i][j-1][1]+abs(loc[j]-loc[j-1]);
			}
			cost = dp[i][j-1][0]+t[i][j-1][0]+abs(loc[j]-loc[i]);
			if (cost < dp[i][j][1] || (cost == dp[i][j][1] && t[i][j-1][0]+abs(loc[j]-loc[i]) < t[i][j][1]))
			{
				dp[i][j][1] = cost;
				t[i][j][1] = t[i][j-1][0]+abs(loc[j]-loc[i]);
			}
		}
	}

	//for (int i = 0; i < n; ++i)
	//	for (int j = i; j < n; ++j)
	//		cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;

	fout << min(dp[0][n-1][0],dp[0][n-1][1]) << endl;

	fin.close();
	fout.close();

	return 0;
}