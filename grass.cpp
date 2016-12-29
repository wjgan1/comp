#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M, top[100005], id[100005], w1[100005], w2[100005], sz[100005], ind, ans;
bool vis[100005];
vector<vector<int> > g, gp, scc, sccp;
queue<int> bfs;
void topo(int u)
{
	if (vis[u])
		return;
	vis[u] = true;
	for (int i = 0; i < gp[u].size(); ++i)
		topo(gp[u][i]);
	top[ind] = u;
	--ind;
}
void idscc(int u, int c)
{
	if (vis[u])
		return;
	vis[u] = true;
	for (int i = 0; i < g[u].size(); ++i)
		idscc(g[u][i],c);
	id[u] = c;
	sz[c]++;
}
int dfsw1(int u)
{
	if (vis[u])
		return w1[u];
	vis[u] = true;
	if (u == id[1])
	{
		w1[u] = sz[u];
		return w1[u];
	}
	vis[u] = true;
	int best = -1;
	for (int i = 0; i < sccp[u].size(); ++i)
		best = max(best,dfsw1(sccp[u][i]));
	if (best == -1)
		w1[u] = -1;
	else
		w1[u] = best+sz[u];
	return w1[u];
}
int dfsw2(int u)
{
	if (vis[u])
		return w2[u];
	vis[u] = true;
	if (u == id[1])
	{
		w2[u] = sz[u];
		return w2[u];
	}
	int best = -1;
	for (int i = 0; i < scc[u].size(); ++i)
		best = max(best,dfsw2(scc[u][i]));
	if (best == -1)
		w2[u] = -1;
	else
		w2[u] = best+sz[u];
	return w2[u];
}
int main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	cin >> N >> M;
	g.resize(N+5);
	gp.resize(N+5);
	scc.resize(N+5);
	sccp.resize(N+5);
	for (int i = 0; i < M; ++i)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		gp[v].push_back(u);
	}
	ind = N;
	for (int i = 1; i <= N; ++i)
		if (!vis[i])
			topo(i);
	int c = 1;
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
	for (int i = 1; i <= N; ++i)
	{
		if (id[top[i]] == 0)
		{
			idscc(top[i],c);
			c++;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < g[i].size(); ++j)
		{
			if (id[i] != id[g[i][j]])
			{
				scc[id[i]].push_back(id[g[i][j]]);
				sccp[id[g[i][j]]].push_back(id[i]);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
	for (int i = 1; i < c; ++i)
		dfsw1(i);
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
	for (int i = 1; i < c; ++i)
		dfsw2(i);
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < scc[i].size(); ++j)
			if (w1[scc[i][j]] != -1 && w2[i] != -1)
				ans = max(ans,w1[scc[i][j]]+w2[i]-sz[id[1]]);
	cout << ans << endl;
}