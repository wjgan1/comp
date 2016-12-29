#include <iostream>
#include <cstdio>
using namespace std;

int N, arr[262149], dp[262149][62], ans;

int main() {
	freopen("262144.in","r",stdin);
	freopen("262144.out","w",stdout);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dp[i][arr[i]] = i+1;
	}
	for (int j = 2; j <= 58; ++j)
		for (int i = 1; i <= N; ++i)
			if (dp[i][j] == 0)
				dp[i][j] = dp[dp[i][j-1]][j-1];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= 58; ++j)
			if (dp[i][j] != 0)
				ans = max(ans,j);
	cout << ans << endl;
}