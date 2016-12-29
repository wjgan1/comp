#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n, k;
int groups;
int s;

int main()
{
	cin >> n >> k;
	for (int i = 0 ; i < k; ++i)
	{
		int gsize, prev;
		cin >> gsize >> prev;
		cout << gsize << endl;
		for (int j = 1; j < gsize; ++j)
		{
			int nxt;
			//cin >> nxt;
			//cout << nxt << endl;
			if (nxt != prev+1)
			{
				s++;
				groups++;
			}
			prev = nxt;
		}
	}
	cout << groups+s-1 << endl;
	return 0;
}