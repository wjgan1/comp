#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

#define endl '\n'

ll M, D, X;

ll cube(ll m) {
	ll i;
	for (i = 1; i*i*i <= m; ++i) ;
	return i-1;
}

void dfs(ll m, ll d, ll x) {
	if (m == 0) {
		X = d > D || (d == D && x > X) ? x : X;
		D = max(D,d);
		return;
	}
	if (m == 1) {
		dfs(0,d+1,x+1);
		return;
	}
	ll c = cube(m);
	ll c1 = c*c*c;
	c--;
	ll c2 = c*c*c;
	dfs(m-c1,d+1,x+c1);
	dfs(c1-1-c2,d+1,x+c2);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> M;
	dfs(M,0,0);
	cout << D << " " << X << endl;
}