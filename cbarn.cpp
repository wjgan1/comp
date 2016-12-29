#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int N, K, arr[1010];
ll cost[10][1010], tsum[1010][1010], ans = 1LL << 62;

void solveDoor(int k, int p, int q, int l, int r, int shft) {
	if (p > q)
		return;
	int mid = (p+q)/2;
	cost[k][mid] = 1LL << 62;
	int ps = 0;
	for (int i = l; i <= min(mid,r); ++i) {
		if ((i == 0 && tsum[(i+shft)%N][(mid+shft)%N] < cost[k][mid]) || (i > 0 && k > 0 && cost[k-1][i-1]+tsum[(i+shft)%N][(mid+shft)%N] < cost[k][mid])) {
			ps = i;
			cost[k][mid] = i == 0 ? tsum[(i+shft)%N][(mid+shft)%N] : cost[k-1][i-1]+tsum[(i+shft)%N][(mid+shft)%N];
		}
	}
	solveDoor(k,p,mid-1,l,ps,shft);
	solveDoor(k,mid+1,q,ps,r,shft);
}

int main()
{
	freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N; ++i)
	{
		ll ts = 0;
		for (int j = i; j < N; ++j) {
			ts += (j-i)*arr[j];
			tsum[i][j] = ts;
		}
		for (int j = 0; j < i; ++j) {
			ts += (N-i+j)*arr[j];
			tsum[i][j] = ts;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j)
			solveDoor(j,0,N-1,0,N-1,i);
		ans = min(ans,cost[K-1][N-1]);
	}
	cout << ans << endl;
}