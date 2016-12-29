/*
ID: wgan8561
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int S, B, c[105];
map<int,int> s[105], b;
int dp[100000];

int dfs(map<int,int> k)
{
	int sum = 0;
	for (map<int,int>::iterator it = k.begin(); it != k.end(); ++it)
	{
		sum *= 10;
		sum += it->second;
	}
	//cout << sum << endl;
	//cout << dp[sum] << endl;
	if (dp[sum] == -1)
		return 1 << 25;
	else if (dp[sum] >= 0)
		return dp[sum];
	dp[sum] = -1;

	int lp = 1 << 28;
	for (int i = 0; i < S+B; ++i)
	{
		bool overflow = false;
		for (map<int,int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
		{
			int tmp = k[it->first];
			k[it->first] = tmp - it->second;
			//cout << it->first << "-" << k[it->first] << " ";
			if (tmp - it->second < 0)
				overflow = true;
		}
		//cout << endl;
		if (!overflow)
			lp = min(lp,c[i]+dfs(k));
		for (map<int,int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
			k[it->first] += it->second;
	}
	dp[sum] = lp;
	/*
	for (map<int,int>::iterator it = k.begin(); it != k.end(); ++it)
		cout << it->first << "-" << it->second << " ";
	cout << lp << endl;
	*/
	return lp;
}
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
  	//cout <<"what" << endl;
    cin >> S;
  	for (int i = 0; i < S; ++i)
  	{
  		int N; cin >> N;
  		for (int j = 0; j < N; ++j)
  		{
  			int a, b; cin >> a >> b;
  			s[i][a] = b;
  		}
  		cin >> c[i];
  	}
  	//cout <<"what" << endl;
  	for (int i = 0; i < 100000; ++i)
  		dp[i] = -2;

  	map<int,int> start;
  	cin >> B;
  	//cout << B << endl;
  	for (int i = 0; i < B; ++i)
  	{
  		int a, d; cin >> a >> d;
  		s[i+S][a] = 1;
  		start.insert(make_pair(a,d));
  		b[i] = d;
  		cin >> c[i+S];
  	}
  	//cout <<"what" << endl;
  	dp[0] = 0;
  	cout << dfs(start) << endl;
}