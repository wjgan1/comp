#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'
#define M 1000000007LL
#define xx first
#define yy second

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll > ppll;

int n, m;
pll seg[400005];
ppll lazy[400005];

ppll a(ll n) {
	ll r00 = 1, r01 = 0, r10 = 0, r11 = 1;
	ll a00 = 1, a01 = 1, a10 = 1, a11 = 0;
	while (n > 0) {
		if (n%2 == 1) {
			ll tmp00 = (r00*a00%M+r01*a10%M)%M;
			ll tmp01 = (r00*a01%M+r01*a11%M)%M;
			ll tmp10 = (r10*a00%M+r11*a10%M)%M;
			ll tmp11 = (r10*a01%M+r11*a11%M)%M;
			r00 = tmp00, r01 = tmp01, r10 = tmp10, r11 = tmp11;
		}
		ll tmp00 = (a00*a00%M+a01*a10%M)%M;
		ll tmp01 = (a00*a01%M+a01*a11%M)%M;
		ll tmp10 = (a10*a00%M+a11*a10%M)%M;
		ll tmp11 = (a10*a01%M+a11*a11%M)%M;
		a00 = tmp00, a01 = tmp01, a10 = tmp10, a11 = tmp11;
		n /= 2;
	}
	return make_pair(make_pair(r00,r01),make_pair(r10,r11));
}

void seg_update(int n, ppll x) {
	ll seg0 = (x.xx.xx*seg[n].xx%M+x.xx.yy*seg[n].yy%M)%M;
	ll seg1 = (x.yy.xx*seg[n].xx%M+x.yy.yy*seg[n].yy%M)%M;
	seg[n].xx = seg0, seg[n].yy = seg1;
}

void lazy_update(int n, ppll x) {
	int c = 2*n;
	ll tmp00 = (x.xx.xx*lazy[c].xx.xx%M+x.xx.yy*lazy[c].yy.xx%M)%M;
	ll tmp01 = (x.xx.xx*lazy[c].xx.yy%M+x.xx.yy*lazy[c].yy.yy%M)%M;
	ll tmp10 = (x.yy.xx*lazy[c].xx.xx%M+x.yy.yy*lazy[c].yy.xx%M)%M;
	ll tmp11 = (x.yy.xx*lazy[c].xx.yy%M+x.yy.yy*lazy[c].yy.yy%M)%M;
	lazy[c].xx.xx = tmp00, lazy[c].xx.yy = tmp01, lazy[c].yy.xx = tmp10, lazy[c].yy.yy = tmp11;
	c++;
	tmp00 = (x.xx.xx*lazy[c].xx.xx%M+x.xx.yy*lazy[c].yy.xx%M)%M;
	tmp01 = (x.xx.xx*lazy[c].xx.yy%M+x.xx.yy*lazy[c].yy.yy%M)%M;
	tmp10 = (x.yy.xx*lazy[c].xx.xx%M+x.yy.yy*lazy[c].yy.xx%M)%M;
	tmp11 = (x.yy.xx*lazy[c].xx.yy%M+x.yy.yy*lazy[c].yy.yy%M)%M;
	lazy[c].xx.xx = tmp00, lazy[c].xx.yy = tmp01, lazy[c].yy.xx = tmp10, lazy[c].yy.yy = tmp11;
}

void lazy_eval(int n, int i, int j) {
	if (lazy[n].xx.xx != 1 || lazy[n].xx.yy != 0 || lazy[n].yy.xx != 0 || lazy[n].yy.yy != 1) {
		seg_update(n,lazy[n]);
		if (i != j)
			lazy_update(n,lazy[n]);
		lazy[n].xx.xx = lazy[n].yy.yy = 1;
		lazy[n].xx.yy = lazy[n].yy.xx = 0;
	}
}

void update(int n, int i, int j, int p, int q, ppll x) {
	if (i > j)
		return;
	lazy_eval(n,i,j);
	if (p > j || q < i)
		return;
	if (p <= i && q >= j) {
		seg_update(n,x);
		if (i < j)
			lazy_update(n,x);
		return;
	}
	int mid = (i+j)/2;
	update(2*n,i,mid,p,q,x);
	update(2*n+1,mid+1,j,p,q,x);
	seg[n].xx = (seg[2*n].xx+seg[2*n+1].xx)%M;
	seg[n].yy = (seg[2*n].yy+seg[2*n+1].yy)%M;
}

ll query(int n, int i, int j, int p, int q) {
	if (i > j)
		return 0;
	lazy_eval(n,i,j);
	if (p > j || q < i)
		return 0;
	if (p <= i && q >= j)
		return seg[n].yy;
	int mid = (i+j)/2;
	return (query(2*n,i,mid,p,q)+query(2*n+1,mid+1,j,p,q))%M;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < 400000; i++) {
		seg[i].xx = 1, seg[i].yy = 0;
		lazy[i].xx.xx = lazy[i].yy.yy = 1;
		lazy[i].xx.yy = lazy[i].yy.xx = 0;
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		update(1,1,n,i,i,a(x));
	}
	for (int i = 1; i <= m; i++) {
		int t,l,r;
		cin >> t >> l >> r;
		if (t == 1) {
			int x; cin >> x;
			update(1,1,n,l,r,a(x));
		}
		else {
			cout << query(1,1,n,l,r) << endl;
		}
	}
}