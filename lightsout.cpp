#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 200
#define HM 1000000007
#define HA 100000007
#define HB 111
#define HC 101

typedef long long ll;

int N, S[2*(MAXN+5)], dp[MAXN+5][MAXN+5][MAXN+5][2][3], 
l[MAXN+5][MAXN+5], r[MAXN+5][MAXN+5], dist[MAXN+5], optm[MAXN+5], ans;
ll hsh[2*(MAXN+5)], pw[2*(MAXN+5)];

ll hext(ll h, int next) {
	return (HA*HB*h+HC+next)%HM;
}

int main() {
	freopen("lightsout.in","r",stdin);
	freopen("lightsout.out","w",stdout);
	
	for (int i = 0; i < MAXN+5; ++i)
		for (int j = 0; j < MAXN+5; ++j)
			for (int k = 0; k < MAXN+5; ++k)
				for (int l = 0; l < 2; ++l)
					for (int m = 0; m < 3; ++m)
						dp[i][j][k][l][m] = 1 << 31;
	
	cin >> N;
	int xpp, ypp; cin >> xpp >> ypp;
	int ox = xpp, oy = ypp;
	int xp, yp; cin >> xp >> yp;
	S[1] = -3; //-3 means exit;
	S[2] = dist[2] = abs(xp-xpp)+abs(yp-ypp);
	for (int i = 3, x, y; i <= N; ++i) {
		cin >> x >> y;
		S[2*i-3] = (xp-xpp)*(y-yp)-(x-xp)*(yp-ypp) > 0 ? -1 : -2; //-1 signifies one concavity, -2 another
		S[2*i-2] = dist[i] = abs(x-xp)+abs(y-yp);
		dist[i] += dist[i-1];
		xpp = xp, ypp = yp, xp = x, yp = y;
	}
	S[2*N-1] = (xp-xpp)*(oy-yp)-(ox-xp)*(yp-ypp) > 0 ? -1 : -2;
	S[2*N] = dist[N+1] = abs(ox-xp)+abs(oy-yp);
	dist[N+1] += dist[N];
	S[2*N+1] = -3;

	for (int i = 1; i <= N+1; ++i) 
		optm[i] = min(dist[i]-dist[1],dist[N+1]-dist[i]);

	pw[0] = 1LL;
	for (int i = 1; i <= 2*N+1; ++i) {
		hsh[i] = hext(hsh[i-1],S[i]);
		pw[i] = HA*HB*pw[i-1]%HM;
	}

	for (int i = 1; i <= N+1; ++i) { //starting position
		for (int j = 1; i+j-1 <= N+1; ++j) { // length
			for (int k = i+1; k+j-1 <= N+1; ++k) {
				int h1 = ((hsh[2*(i+j-1)-1]-pw[2*j-1]*hsh[2*i-1-1])%HM+HM)%HM;
				int h2 = ((hsh[2*(k+j-1)-1]-pw[2*j-1]*hsh[2*k-1-1])%HM+HM)%HM;
				if (h1 == h2) {
					r[i][j] = k;
					break;
				}
			}
			for (int k = i-1; k >= 1; --k) {
				int h1 = ((hsh[2*(i+j-1)-1]-pw[2*j-1]*hsh[2*i-1-1])%HM+HM)%HM;
				int h2 = ((hsh[2*(k+j-1)-1]-pw[2*j-1]*hsh[2*k-1-1])%HM+HM)%HM;
				if (h1 == h2) {
					l[i][j] = k;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= N+1; ++i) {
		for (int j = 1; j <= i; ++j)
			dp[1][i][j][0][0] = -optm[j];
		for (int j = i; j <= N+1; ++j)
			dp[i][N+1][j][1][0] = -optm[j];
	}

	for (int j = N+1; j >= 1; --j) {
		for (int i = 2; i+j-1 <= N+1-1; ++i) {
			for (int s = i; s <= i+j-1; ++s) {
				dp[i][i+j-1][s][0][1] = dp[i-1][i+j-1][s][0][0]+dist[i]-dist[i-1];
				dp[i][i+j-1][s][0][1] = max(dp[i][i+j-1][s][0][1],dp[l[i][j]][l[i][j]+j-1][s-i+l[i][j]][0][1]);
				dp[i][i+j-1][s][0][2] = dp[i][i+j-1+1][s][1][0]+dist[i+j-1+1]-dist[i];
				dp[i][i+j-1][s][0][2] = max(dp[i][i+j-1][s][0][2],dp[l[i][j]][l[i][j]+j-1][s-i+l[i][j]][0][2]);
				dp[i][i+j-1][s][1][2] = dp[i][i+j-1+1][s][1][0]+dist[i+j-1+1]-dist[i+j-1];
				dp[i][i+j-1][s][1][2] = max(dp[i][i+j-1][s][1][2],dp[l[i][j]][l[i][j]+j-1][s-i+l[i][j]][1][2]);
				dp[i][i+j-1][s][1][1] = dp[i-1][i+j-1][s][0][0]+dist[i+j-1]-dist[i-1];
				dp[i][i+j-1][s][1][1] = max(dp[i][i+j-1][s][1][1],dp[l[i][j]][l[i][j]+j-1][s-i+l[i][j]][1][1]);
			}
		}
		for (int i = N+1-1-j+1; i >= 1+1; --i) {
			for (int s = i; s <= i+j-1; ++s) {
				dp[i][i+j-1][s][0][1] = max(dp[i][i+j-1][s][0][1],dp[r[i][j]][r[i][j]+j-1][s-i+r[i][j]][0][1]);
				dp[i][i+j-1][s][0][2] = max(dp[i][i+j-1][s][0][2],dp[r[i][j]][r[i][j]+j-1][s-i+r[i][j]][0][2]);
				dp[i][i+j-1][s][1][1] = max(dp[i][i+j-1][s][1][1],dp[r[i][j]][r[i][j]+j-1][s-i+r[i][j]][1][1]);
				dp[i][i+j-1][s][1][2] = max(dp[i][i+j-1][s][1][2],dp[r[i][j]][r[i][j]+j-1][s-i+r[i][j]][1][2]);
				dp[i][i+j-1][s][0][0] = min(dp[i][i+j-1][s][0][1],dp[i][i+j-1][s][0][2]);
				dp[i][i+j-1][s][1][0] = min(dp[i][i+j-1][s][1][1],dp[i][i+j-1][s][1][2]);
			}
		}
	}

	for (int i = 1; i <= N+1; ++i) {
		ans = max(ans,dp[i][i][i][0][0]);
	cout << ans << endl;
}