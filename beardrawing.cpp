#include <iostream>
#include <vector>
using namespace std;

int N, start, leg[100005], nb[100005];
vector<vector<int> > edg;
bool deg3[100005], vis[100005], ans = true;

void countLegs(int u) {
	if (edg[u].size() >= 3) {
		leg[u]++;
		return;
	}
	if (vis[u])
		return;
	vis[u] = true;
	for (int i = 0; i < edg[u].size(); ++i)
		countLegs(edg[u][i]);
}

void countNeighbors(int u, int v) {
	if (vis[u])
		return;
	vis[u] = true;
	if (edg[u].size() >= 3 && v != -1) {
		cout << u << " " << v << endl;
		cout << edg[u].size() << " " << leg[u] << endl;
		cout << edg[v].size() << " " << leg[v] << endl;
		if (edg[u].size()-min(leg[u],2) > 1)
			nb[v]++;
		if (edg[v].size()-min(leg[v],2) > 1)
			nb[u]++;
	}
	if (edg[u].size() >= 3)
		v = u;
	for (int i = 0; i < edg[u].size(); ++i)
		countNeighbors(edg[u][i],v);
}
/*
bool dfs(int u) {
	if (vis[u])
		return false;
	vis[u] = true;
	int lg = 0;
	for (int i = 0; i < edg[u].size(); ++i)
		if (dfs(edg[u][i]))
			++lg;
	if (edg[u].size() >= 3 && edg[u].size()-min(leg[u],2) > 1 && lg > 1 && u != start) {
		ans = false;
	return lg > 0 || (edg[u].size() >= 3 && edg[u].size()-min(leg[u],2) > 1);
}
*/
int main() {
	cin >> N;
	edg.resize(N+5);
	for (int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v;
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i)
		if (edg[i].size() == 1)
			countLegs(i);	
	//int start = 0;
	for (int i = 1; i <= N; ++i) {
		vis[i] = false;
		if (edg[i].size() >= 3)
			start = i;
	}
	countNeighbors(start,-1);
	//cout << ans << endl;
	for (int i = 1; i <= N; ++i) {
		if (nb[i] > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}