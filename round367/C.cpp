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

ll N, c[100005], dp[100005][2];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> c[i];
	string prev, prevrev;
	for (int i = 0; i < N; ++i) {
		string s, str;
		cin >> s;
		for (int j = s.size()-1; j >= 0; --j)
			str += s[j];
		if (i == 0) {
			dp[i][1] = c[i];
			prev = s;
			prevrev = str;
			continue;
		}
		//cout << i << " " << prev << " " << s << endl;
		dp[i][0] = dp[i][1] = 1LL << 60;
		dp[i][0] = prev <= s ? min(dp[i][0],dp[i-1][0]) : dp[i][0];
		dp[i][0] = prevrev <= s ? min(dp[i][0],dp[i-1][1]) : dp[i][0];
		dp[i][1] = prev <= str ? min(dp[i][1],dp[i-1][0]+c[i]) : dp[i][1];
		dp[i][1] = prevrev <= str ? min(dp[i][1],dp[i-1][1]+c[i]) : dp[i][1];
		if (dp[i][0] >= 1LL << 60 && dp[i][1] >= 1LL << 60) {
			cout << -1 << endl;
			return 0;
		}
		dp[i][0] = min(dp[i][0],1LL << 60);
		dp[i][1] = min(dp[i][1],1LL << 60);
		prev = s;
		prevrev = str;
	}
	cout << min(dp[N-1][0],dp[N-1][1]) << endl;
}