/*
ID: wgan8561
PROG: humble
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int k, n;
int p[101];
int l[101];
int h[100001];
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    cin >> k >> n;
    for (int i = 0; i < k; ++i)
    {
    	cin >> p[i];
    }
    
    h[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        h[i] = (1 << 31)-1;
        for (int j = 0; j < k; ++j)
            h[i] = min(h[i],p[j]*h[l[j]]);
        for (int j = 0; j < k; ++j)
            if (h[i] == p[j]*h[l[j]])
                ++l[j];
    }
    cout << h[n] << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}