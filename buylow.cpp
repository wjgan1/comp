/*
ID: wgan8561
PROG: buylow
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int N, val[5005], dp[5005], X;
vector<int> rep[5005];

void add(int i, int j)
{
	//cout << i << " " << j << endl;
	int M = max(rep[i].size(),rep[j].size());
	//cout << M << endl;
	rep[i].resize(M);
	int ov = 0;
	for (int k = 0; k < M; ++k)
	{
		rep[i][k] = k >= rep[j].size() ? rep[i][k]+ov : rep[i][k]+rep[j][k]+ov;
		ov = rep[i][k]/10;
		rep[i][k] %= 10;
	}
	if (ov > 0)
		rep[i].push_back(ov);
	/*
	for (int k = rep[i].size()-1; k >= 0; --k)
		cout << rep[i][k];
	//cout << endl;
	*/
}

int main()
{
	//freopen("buylow.in","r",stdin);
	//freopen("buylow.out","w",stdout);
	double d = 3.0%2.0;
	//cout << i << endl;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> val[i];

	for (int i = 1; i <= N; ++i)
	{
		dp[i] = 1;
		for (int j = i-1; j > 0; --j)
			if (val[j] > val[i] && dp[j]+1 > dp[i])
				dp[i] = dp[j]+1;
		X = max(X,dp[i]);
	}
	for (int i = 1; i <= N; ++i)
		if (dp[i] == X)
			rep[i].push_back(1);
	val[0] = 1 << 30;
	dp[0] = 0;
	for (int i = N; i > 0; --i)
	{
		for (int j = i-1; j >= 0; --j)
		{
			if (val[j] > val[i] && dp[j] == dp[i]-1)
				add(j,i);
			else if (val[j] == val[i])
				break;
		}
		//cout << rep[i].size() << endl;
	}
	cout << X << " ";
	for (int i = rep[0].size()-1; i >= 0; --i)
		cout << rep[0][i];
	cout << endl;
}