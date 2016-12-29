#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, K;
vector<int> list;

int main()
{
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		bool need = true;
		for (int j = 2; j*j < N; ++j)
		{
			if (i%j == 0 && max(j,i/j)%min(j,i/j) != 0)
			{
				need = false;
				break;
			}
		}
		if (need)
		{
			++K;
			list.push_back(i);
		}
	}
	cout << K << endl;
	for (int i = 0; i < K-1; ++i)
		cout << list[i] << " ";
	if (K > 0)
		cout << list[K-1] << endl;
}