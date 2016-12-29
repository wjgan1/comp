#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
 
int n, hi;
int hand[100000];
long long ans;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    fin >> n;
    for (int i = 0; i < n; ++i)
    	fin >> hand[i];

    hi = ans = hand[0];
    for (int i = 1; i < n; ++i)
    {
    	if (hand[i] > hi)
    	{
    		ans += hand[i]-hi;
    		hi = hand[i];
    	}  
    	else if (hand[i] < hi)
    	{
    		hi = hand[i];
    	}
    }
    fout << ans << endl;
 
    fclose(stdin);
    fclose(stdout);
 
    return 0;
}