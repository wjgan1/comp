//foreverbronze
//problem link
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define m_n 100000

int n, xi, yi, xf, yf;
int ans = -1;
int w[4];

int main()
{
	cin >> n >> xi >> yi >> xf >> yf;
	string str;
	cin >> str;
	
	int x = xi;
	int y = yi;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		int dx = xf-x;
		if (dx >= 0 && dx >= w[1])
			break;
		else if (dx < 0 && dx <= -1*w[3])
			break;
		int dy = yf-y;
		if (dy >= 0 && dy >= w[0])
			break;
		else if (dy < 0 && dy <= -1*w[2])
			break;

		for (int j = 0; j < 3; ++j)
			cout << w[i] << " ";
		cout << endl;

		if (str[i] == 'N')
		{
			++w[0];
			++y;
		}
		else if (str[i] == 'E')
		{
			++w[1];
			++x;
		}
		else if (str[i] == 'S')
		{
			++w[2];
			--y;
		}
		else
		{
			++w[3];
			--x;
		}
	}

	if (i > n)
		cout << -1 << endl;
	else
		cout << i << endl;
	return 0;
}