/*
ID: wgan8561
PROG: money
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
#define in2 "money.in"
#define out1 "data.out"
#define out2 "money.out"

int c, cn[26];
long long n, dp[26][10001];


int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> c >> n;

	for (int i = 1; i <= c; ++i)
		fin >> cn[i];

	dp[0][0] = 1;
	for (int i = 1; i <= c; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] += dp[i-1][j];
			if (j-cn[i] >= 0)
				dp[i][j] += dp[i][j-cn[i]];
		}
	}

	fout << dp[c][n] << endl;

	fin.close();
	fout.close();

	return 0;
}