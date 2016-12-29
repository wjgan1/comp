#include <iostream>
#include <queue>
using namespace std;

int L, N, p, t, seg[100005][2], ans;
int dpl[100005], dpr[100005][105];
int dp[10000005], q;

int main() {
	cin >> L >> N >> p >> t;
	for (int i = 1 ; i <= N; i++)
		cin >> seg[i][0] >> seg[i][1];
	if (p > 100) {
		for (int i = 0; i <= L/p; i++)
			dp[i] = 1 << 30;
		dp[0] = -t;
		for (int i = 1; i <= N; i++) {
			for (int j = (seg[i][1]-seg[i][0])/p; j > 0; j--) {
				while (dp[q+1] != 0 && dp[q+1] <= seg[i][1]-j*p-t)
					q++;
				dp[q+j] = min(dp[q+j],max(seg[i][0]+j*p,dp[q]+t+j*p));
			}
		}
		for (int i = 0; i <= L/p; i++)
			if (dp[i] <= L)
				ans = i;
		cout << ans << endl;
	}
	else {
		q = N+1;
		dpl[N] = (seg[N][1]-seg[N][0])/p;
		for (int i = N-1; i >= 1; i--) {
			int lr = seg[i][1]-seg[i][0];
			int a = lr/p;
			int b = lr%p;
			for (int j = 0; j < min(p,lr); j++) {
				int x = seg[i][1]-j+t;
				while (x <= seg[q-1][0])
					q--;
				dpr[i][j] = dpl[q];
				if (x >= seg[q-1][0] && q-1 > i)
					dpr[i][j] = max(dpr[i][j],(seg[q-1][1]-x)/p+dpr[q-1][(seg[q-1][1]-x)%p]);
			}
			dpl[i] = max(dpl[i+1],a+dpr[i][b]);
		}
		cout << dpl[1] << endl;
	}
}