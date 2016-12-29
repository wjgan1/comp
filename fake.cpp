#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n;
int arr[1000];
bool hap = false;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    
 	cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
    {
        bool row = true;
        if (arr[0] != 0)
            row = false;
        for (int j = 1; j < n; ++j)
            if (arr[j] != arr[j-1]+1)
                row = false;
        if (row)
        {
            hap = true;
            break;
        }
        for (int j = 0; j < n; ++j)
            if (j%2 == 0)
                arr[j] = (arr[j]+1)%n;
            else
                arr[j] = (arr[j]+n-1)%n;

    }
    
    if (hap)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}