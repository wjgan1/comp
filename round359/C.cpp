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

int N, a[100005], ans;
vector<vector<pair<int,int> > > e(100005);

int dfs(int u, int p, ll d, ll md) {
	int c = 1;
	for (int i = 0; i < e[u].size(); ++i)
		if (e[u][i].first != p)
			c += dfs(e[u][i].first,u,d+e[u][i].second,min(md,d+e[u][i].second));
	if (max(d,d-md) > a[u])
		return 0;
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	for (int i = 1; i < N; ++i) {
		int p, c;
		cin >> p >> c;
		e[i+1].push_back(make_pair(p,c));
		e[p].push_back(make_pair(i+1,c));
	}
	cout << N-dfs(1,0,0,1LL<<62) << endl;
}