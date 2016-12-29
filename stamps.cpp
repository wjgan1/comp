/*
ID: wgan8561
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int n, k, dp[2000005], stamps[50];
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    cin >> k >> n;
    for (int i = 0; i < n; ++i)
    	cin >> stamps[i];

    dp[0] = 0;
    for (int i = 1; i <= 2000000; ++i)
    {
    	dp[i] = k+1;
    	for (int j = 0; j < n; ++j)
    		if (i-stamps[j] >= 0)
    			dp[i] = min(dp[i],dp[i-stamps[j]]+1);
    	//cout << i << " " << dp[i] << endl;
    }

    int ans = 0;
    for ( ; dp[ans] <= k; ++ans)
    	continue;

    cout << --ans << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}