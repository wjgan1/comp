#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

#define inf 1 << 30

int ans;
ll N, M, T;
int p[5005][5005], d[5005][5005];
bool vis[5005];
vector<pi> e[5005];

int s_d(int u, int l) {
	if (l < 1)
		return inf;
	if (d[u][l] != -1)
		return d[u][l];
	if (u == N)
		return l == 1 ? 0 : inf;
	int b_d = inf, b_i = N;
	for (int i = 0; i < e[u].size(); i++) {
		int dist = min(0LL+(inf),0LL+e[u][i].second+s_d(e[u][i].first,l-1));
		if (dist < b_d) {
			b_d = dist;
			b_i = e[u][i].first;
		}
	}
	p[u][l] = b_i;
	return d[u][l] = b_d;
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= M; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		e[u].push_back(make_pair(v,t));
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = -1;
	for (int i = 1; i <= N; i++)
		if (s_d(1,i) <= T)
			ans = i;
	cout << ans << endl;
	for (int i = 1; ans > 1; i = p[i][ans], ans--)
		cout << i << endl;
	cout << N << endl;
}