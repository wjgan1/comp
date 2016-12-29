/*
ID: wgan8561
PROG: kimbits
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

long long n, l, dp[32][32], arr[32];
long long x;

int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);

    cin >> n >> l >> x;
    for (int i = 0; i <= n; ++i)
    	dp[0][i] = 1;
    for (int i = 1; i <= l; ++i)
    {
    	dp[i][0] = 1;
    	for (int j = 1; j <= n; ++j)
    		dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
    }
    for (int i = 0; i <= l; ++i)
    	for (int j = n; j > 0; --j)
    		dp[i][j] -= dp[i][j-1];
    for (int i = l; i >= 0; --i)
    {
    	if (x == 0)
    		break;
    	long long sum = 0;
    	for (int j = 0; j <= n; ++j)
    	{
    		sum += dp[i][j];
    		if (sum >= x)
    		{
    			x = x-sum+dp[i][j];
    			arr[j] = 1;
    			break;
    		}
    	}
    }
    for (int i = n; i > 0; --i)
    	cout << arr[i];
    cout << endl;

 	fclose(stdin);
 	fclose(stdout);
    return 0;
}