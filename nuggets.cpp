/*
ID: wgan8561
PROG: nuggets
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;

int N, val[10], ans;
bool dp[1000000];

int main()
{
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> val[i];
		dp[val[i]] = true;
	}
	for (int i = 1; i < 1000000; ++i)
	{
		for (int j = 0; j < N; ++j)
			if (i-val[j] > 0 && dp[i-val[j]])
				dp[i] = true;
		if (!dp[i])
			ans = i;
	}
	if (ans == 999999)
		cout << 0 << endl;
	else
		cout << ans << endl;
}