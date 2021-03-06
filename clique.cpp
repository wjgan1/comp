#include <iostream>
#include <cstdlib>
using namespace std;

int N, arr[1000005], st[1000005];
int best = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i)
		for (int j = arr[i]*2; j <= 1000000; j += arr[i])
			st[j] = max(st[j],st[arr[i]]+1);

	for (int i = 0; i < N; ++i)
		best = max(best,st[arr[i]]);
	cout << best+1 << endl;
}