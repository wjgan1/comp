#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

string str;
int oparens, cparens, sum;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);

  	cin >> str;

  	for (int i = 0; i < str.length(); ++i)
  	{
  		if (str[i] == '(')
        {
  			sum++;
            oparens++;
        }
  		else
  		{
  			sum--;
  			cparens++;
  		}
        if (sum == 1)
            oparens = 0;
  		if (sum < 0)
  		    break;
  	}
    if (sum < 0)
        cout << cparens << endl;
    else if (sum > 0)
        cout << oparens << endl;
    else
        cout << 0 << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}