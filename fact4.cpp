/*
ID: wgan8561
PROG: fact4
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

int n, ans = 1;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);

   	cin >> n;
   	int ans2 = 1;
    for (int i = 2; i <= n; ++i)
    {
    	ans *= i;
    	ans2 *= i;
    	while (ans%10 == 0)
    	{
    		ans /= 10;
    		ans2 /= 10;
    	}
    	ans = ans%1000000;
    	ans2 = ans2%10;
    	//cout << i << " " << ans << " " << ans2 << endl;
    }
    cout << ans%10 << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}