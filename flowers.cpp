#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define M 1000000007

int t, k;
int dp[100001];
int part[100001];
 
int main()
{
  	ios_base::sync_with_stdio(0);

  	cin >> t >> k;
  	dp[0] = 1;
  	part[0] = 1;
  	for (int i = 1; i <= 100000; ++i)
  	{
  		dp[i] = dp[i-1]%M;
  		if (i >= k)
  			dp[i] = (dp[i]+dp[i-k])%M;
  		//cout << i << " " << dp[i] << endl;
  		part[i] = (dp[i]+part[i-1])%M;
  	}
  	//cout << endl;
  	for (int i = 0; i < t; ++i)
  	{
  		int a, b;
  		cin >> a >> b;
  		int ans = part[b]-part[a-1];
  		if (ans < 0)
  			ans += M;
  		cout << ans << endl;
  	}
  	
    return 0;
}