#include <iostream>
using namespace std;
 
typedef long long ll;
#define endl '\n'
#define SEGN 500005
 
int N, a[100005];
ll ans, dp[100005], seg[SEGN];
 
void update(int x, int l, int r, int i, ll v) {
	if (l > r || l > i || r < i)
		return;
	if (l == r && l == i) {
		seg[x] = min(seg[x],v);
		return;
	}
	update(2*x,l,(l+r)/2,i,v);
	update(2*x+1,(l+r)/2+1,r,i,v);
	seg[x] = min(seg[2*x],seg[2*x+1]);
}
 
ll query(int x, int l, int r, int i, int j) {
	if (l > r || l > j || r < i)
		return 1LL << 62;
	if (l >= i && r <= j)
		return seg[x];
	return min(query(2*x,l,(l+r)/2,i,j),query(2*x+1,(l+r)/2+1,r,i,j));
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < SEGN; ++i)
		seg[i] = 1LL << 62;
	for (int i = 1; i < N; ++i)
		cin >> a[i];
	a[N] = N;
	dp[N] = 0;
	update(1,1,N,N,dp[N]+N);
	for (int i = N-1; i >= 1; --i) {
		dp[i] = N-i-a[i]+query(1,1,N,i,a[i]);
		ans += dp[i];
		update(1,1,N,i,dp[i]+i);
	}
	cout << ans << endl;
	return 0;
}