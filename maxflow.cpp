#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi > vii;
typedef set<int> si;
typedef set<int>::iterator sit;
typedef map<int,int> mi;
typedef map<int,int>::iterator mit;
typedef priority_queue<int> pqi;
typedef priority_queue<pi > pqii;

int N, K, depth[100005], pref[100005], f[100005][17], ans;
bool vis[100005];
vvi adj;

void calc(int u, int p, int d)
{
	if (vis[u])
		return;
	vis[u] = true;
	depth[u] = d;
	int pw = 0;
	int pd = 1;
	while (pd <= d)
	{
		f[u][pw] = pw == 0 ? p : f[f[u][pw-1]][pw-1];
		pw++;
		pd *= 2;
	}
	for (int i = 0; i < adj[u].size(); ++i)
		calc(adj[u][i],u,d+1);
}

int calcSum(int u)
{
	if (vis[u])
		return 0;
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i)
		//if (!vis[adj[u][i]])
		pref[u] += calcSum(adj[u][i]);
	//cout << u << " " << pref[u] << endl;
	return pref[u];
}

int par(int u, int p)
{
	for (int k = 16, x = 1 << 16; k >= 0; --k, x /= 2)
	{
		if (p >= x)
		{
			p = p-x;
			u = f[u][k];
		}
	}
	return u;
}

int lca(int u, int v)
{
	if (depth[v] > depth[u])
		return lca(v,u);
	u = par(u,depth[u]-depth[v]);
	//cout << u << endl;
	for (int k = 16; k >= 0; --k)
	{
		if (f[u][k] != f[v][k])
		{
			u = f[u][k];
			v = f[v][k];
		}
	}
	while (u != v)
	{
		u = f[u][0];
		v = f[v][0];
	}
	return u;
}

int main()
{
	//freopen("maxflow.in","r",stdin);
	//freopen("maxflow.out","w",stdout);


	cin >> N >> K;
	adj.resize(N+5);
	for (int i = 1; i < N; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	calc(1,0,0);
	/*
	for (int i = 1; i <= N; ++i)
	{
		int j = 0;
		cout << depth[i] << endl;
		while (f[i][j] != 0)
		{
			cout << f[i][j] << " ";
			j++;
		}
		cout << endl;
	}
	*/
	for (int i = 1; i <= K; ++i)
	{
		int u, v;
		cin >> u >> v;
		//cout << u << " " << v << endl;
		int l = lca(u,v);
		//cout << u << " " << v << " " << l << endl;
		pref[u]++;
		pref[v]++;
		pref[l]--;
		pref[f[l][0]]--;
	}

	for (int i = 1; i <= N; ++i)
	{
		//cout << pref[i] << endl;
		vis[i] = false;
	}

	calcSum(1);

	for (int i = 1; i <= N; ++i)
	{
		//cout << pref[i] << endl;
		ans = max(ans,pref[i]);
	}
	cout << ans << endl;
}