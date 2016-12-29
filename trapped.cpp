#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

int N, ans;
map<int,int> bale;
struct range {
	int l, r, cst;
	range(int ll, int rr) {
		l = ll;
		r = rr;
		cst = (r-l)-min(bale[l],bale[r]);
	}
	bool operator<(const range &rhs) const {
		if (cst != rhs.cst)
			return cst > rhs.cst;
		if (l != rhs.l)
			return l < rhs.l;
		return r < rhs.r;
	}
};
set<range> rngs;

int main()
{
	freopen("trapped.in","r",stdin);
	freopen("trapped.out","w",stdout);
	/*
	bale[1] = 0;
	bale[2] = 0;
	bale[3] = 0;
	bale[4] = 0;
	rngs.insert(range(1,2));
	set<range>::iterator sit = rngs.find(range(1,2));
	cout << (sit == rngs.end()) << endl;
	*/
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int sz, pos;
		cin >> sz >> pos;
		bale[pos] = sz;
	}
	for (map<int,int>::iterator mit = ++bale.begin(); mit != bale.end() && bale.size() > 0; ++mit) {
		//cout << (--mit)->first << " " << (++mit)->first << endl;
		rngs.insert(range((--mit)->first,(++mit)->first));
	}
	for ( ; rngs.size() > 0; ) {
		range rng = *(rngs.begin());
		if (rng.cst <= 0)
			break;
		rngs.erase(rngs.begin());
		int lsz = bale[rng.l], rsz = bale[rng.r];
		//cout << rng.l << " " << rng.r << " " << lsz << " " << rsz << " " << rng.cst << endl;
		if (lsz < rsz) {
			map<int,int>::iterator mit = bale.find(rng.l);
			if (mit != bale.begin()) {
				--mit;
				rngs.erase(range(mit->first,rng.l));
				rngs.insert(range(mit->first,rng.r));
			}
			bale.erase(rng.l);
		}
		else {
			map<int,int>::iterator mit = bale.upper_bound(rng.r);
			if (mit != bale.end()) {
				rngs.erase(range(rng.r,mit->first));
				rngs.insert(range(rng.l,mit->first));
			}
			bale.erase(rng.r);
		}
	}
	for (map<int,int>::iterator mit = ++bale.begin(); mit != bale.end() && bale.size() > 0; ++mit) {
	//	cout << mit->first << endl;
		ans -= (--mit)->first-(++mit)->first;
	}
	cout << ans << endl;
}