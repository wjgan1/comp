#include <iostream>
#include <vector>
using namespace std;

int N, M, colc;
char c;
vector<vector<pair<int,bool> > > adj;
vector<int> R, B, zero, one;
bool vis[100005], col[100005], ccol;

void dfs(int u, bool color) {
	if (vis[u]) {
		if (color != col[u])
			one.resize(N+5);
		return;
	}
	if (color)
		one.push_back(u);
	else
		zero.push_back(u);
	col[u] = color;
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (adj[u][i].second == ccol)
			dfs(adj[u][i].first,color);
		else
			dfs(adj[u][i].first,!color);
	}
} 

int main() {
	cin >> N >> M;
	adj.resize(N+5);
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v >> c;
		adj[u].push_back(make_pair(v,c=='R'));
		adj[v].push_back(make_pair(u,c=='R'));
	}
	ccol = false;	
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			dfs(i,true);
			if (one.size() > N) {
				R.resize(N+5);
				break;
			}
			if (one.size() < zero.size())
				for (int j = 0; j < one.size(); ++j)
					R.push_back(one[j]);
			else
				for (int j = 0; j < zero.size(); ++j)
					R.push_back(zero[j]);
			one.resize(0);
			zero.resize(0);
		}
	}
	one.resize(0);
	zero.resize(0);
	ccol = true;
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			dfs(i,true);
			if (one.size() > N) {
				B.resize(N+5);
				break;
			}
			if (one.size() < zero.size())
				for (int j = 0; j < one.size(); ++j)
					B.push_back(one[j]);
			else
				for (int j = 0; j < zero.size(); ++j)
					B.push_back(zero[j]);
			one.resize(0);
			zero.resize(0);
		}
	}
	if (R.size() > N && B.size() > N)
		cout << -1 << endl;
	else if (R.size() < B.size()) {
		cout << R.size() << endl;
		for (int i = 0; i < R.size(); ++i)
			cout << R[i] << " ";
		cout << endl;
	}
	else {
		cout << B.size() << endl;
		for (int i = 0; i < B.size(); ++i)
			cout << B[i] << " ";
		cout << endl;
	}
}