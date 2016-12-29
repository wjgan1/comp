/*
ID: wgan8561
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, M, val[20], dp1[20][20], dp2[21][21], ans;



int main()
{
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);

	cin >> N >> T >> M;
	for (int i = 0; i < N; ++i)
		cin >> val[i];

	for (int i = 0; i < N; ++i)
	{
		vector<int> v;
		for (int j = i; j < N; ++j)
		{
			v.push_back(val[j]);
			sort(v.begin(),v.end());
			int rem = T, cnt = 0;
			while (cnt < v.size() && rem > 0)
			{
				rem -= v[cnt];
				++cnt;
			}
			//cout << i << " " << j << " " << rem << endl;
			if (rem < 0)
				--cnt;
			dp1[i][j] = cnt;
		}
	}
	/*
	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
			cout << i << " " << j << " " << dp1[i][j] << endl;
	*/
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 0; k < j; ++k)
				dp2[i][j] = max(dp2[i][j],max(dp2[i][j-1],dp2[i-1][k]+dp1[k][j-1]));
	/*
	cout << dp1[1][2] << endl;
	cout << dp2[0][0]+dp1[1][2] << endl;

	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			cout << i << " " << j << " " << dp2[i][j] << endl;
	*/
	cout << dp2[M][N] << endl;
}