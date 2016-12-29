/*
ID: wgan8561
PROG: range
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int N, field[251][251], pre[251][251];

int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		string line;
		cin >> line;
		int sum = 0;
		for (int j = 1; j <= N; ++j)
		{
			field[i][j] = line[j-1]-'0';
			sum += field[i][j];
			field[i][j] = field[i-1][j]+sum;
		}
	}
	
	for (int k = 1; k < N; ++k)
	{
		int cnt = 0;
		for (int i = 1; i <= N-k; ++i)
			for (int j = 1; j <= N-k; ++j)
				if (field[i+k][j+k]-field[i-1][j+k]-field[i+k][j-1]+field[i-1][j-1] == (k+1)*(k+1))
					++cnt;
		if (cnt > 0)
			cout << k+1 << " " << cnt << endl;
	}
}