#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, coin[1005];

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i];
		if (coin[i] == 1)
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << "1" << endl;
}