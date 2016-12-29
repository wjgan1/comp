#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

#define endl '\n'

int N, M, K, dp[1002][1002][12], lng[1002][1002], ans;
string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	cin >> s >> t;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (s[i-1] == t[j-1])
				lng[i][j] = lng[i-1][j-1]+1;
	for (int k = 1; k <= K; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				dp[i][j][k] = 1 << 31;
	for (int k = 1; k <= K; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				int d = lng[i][j];
				if (dp[i-d][j-d][k-1] == 1 << 31) {
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i-1][j-1][k]));
					continue;
				}
				dp[i][j][k] = max(max(dp[i-d][j-d][k-1]+d,dp[i-1][j][k]),max(dp[i][j-1][k],dp[i-1][j-1][k]));
			}
		}
	}
	for (int k = 1; k <= K; ++k)
		if (dp[N][M][k] >= K)
			ans = max(ans,dp[N][M][k]);
	cout << ans << endl;
}