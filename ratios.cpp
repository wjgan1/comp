/*
ID: wgan8561
PROG: ratios
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

int mix[4][3];
int ans[4];
int sum = 1 << 30;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);

    for (int i = 0; i < 4; ++i)
    	for (int j = 0; j < 3; ++j)
    		cin >> mix[i][j];
    for (int i = 0; i < 100; ++i)
    	for (int j = 0; j < 100; ++j)
    		for (int k = 0; k < 100; ++k)
    		{
    			int a = i*mix[1][0]+j*mix[2][0]+k*mix[3][0];
    			int b = i*mix[1][1]+j*mix[2][1]+k*mix[3][1];
    			int c = i*mix[1][2]+j*mix[2][2]+k*mix[3][2];
    			int r = -1;
    			if ((a == 0 && mix[0][0] == 0) || (mix[0][0] != 0 && r == -1 && a%mix[0][0] == 0) || (mix[0][0] != 0 && a/mix[0][0] == r && a%mix[0][0] == 0))
    			{
    				r = mix[0][0] == 0 ? r : a/mix[0][0];
    				if ((b == 0 && mix[0][1] == 0) || (mix[0][1] != 0 && r == -1 && b%mix[0][1] == 0) || (mix[0][1] != 0 && b/mix[0][1] == r && b%mix[0][1] == 0))
    				{
    					r = mix[0][1] == 0 ? r : b/mix[0][1];
    					//if (i == 8 && j == 1 && k == 5)
    					//	cout << a << " " << b << " " << c << " " << r << endl;
    					if ((c == 0 && mix[0][2] == 0) || (mix[0][2] != 0 && r == -1 && c%mix[0][2] == 0) || (mix[0][2] != 0 && c/mix[0][2] == r && c%mix[0][2] == 0))
    					{
							r = mix[0][2] == 0 ? r : c/mix[0][2];
							r = r == -1 ? 0 : r;
							int s = i+j+k;
							if (s < sum && s != 0)
							{
								ans[0] = i;
    							ans[1] = j;
    							ans[2] = k;
    							ans[3] = r;
    							sum = s;
							}
    					}
    				}
    			}
    		}
 	
    if (sum == 1 << 30)
    	cout << "NONE" << endl;
    else
    	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;

 	fclose(stdin);
 	fclose(stdout);
    return 0;
}