/*
ID: wgan8561
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;

int N, val[101], pre[101], dp[101][101];

int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> val[i];
		pre[i] = pre[i-1]+val[i];
		dp[i][i] = val[i];
	}

	for (int k = 1; k < N; ++k)
	{
		for (int i = 1; i <= N-k; ++i)
		{
			int l = pre[i+k-1]-pre[i-1];
			int r = pre[i+k]-pre[i];
			dp[i][i+k] = max(val[i]+r-dp[i+1][i+k],val[i+k]+l-dp[i][i+k-1]);
		}
	}

	cout << dp[1][N] << " " << pre[N]-dp[1][N] << endl;
}