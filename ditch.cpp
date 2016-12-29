/*
ID: wgan8561
PROG: ditch
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N, M, flow[205], bef[205], nxt, ans;
bool vis[205];
vector<map<int,int> > adj;

int main()
{
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);

	cin >> M >> N;
	adj.resize(N+5);
	for (int i = 0; i < M; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		if (adj[a].find(b) != adj[a].end())
			adj[a][b] += c;
		else
			adj[a].insert(make_pair(b,c));
		adj[b].insert(make_pair(a,0));
	}

	while (true)
	{
		for (int i = 1; i <= N; ++i)
		{
			flow[i] = 0;
			vis[i] = false;
			bef[i] = 0;
		}
		flow[1] = 1 << 30;
		nxt = 1;
		while (nxt)
		{
			vis[nxt] = true;
			for (map<int,int>::iterator it = adj[nxt].begin(); it != adj[nxt].end(); ++it)
			{
				int f = min(flow[nxt],it->second), v = it->first;
				if (f > flow[v])
				{
					flow[v] = f;
					bef[v] = nxt;
				}
			}
			nxt = 0;
			for (int i = 1; i <= N; ++i)
				if ((nxt == 0 && !vis[i] && flow[i] > 0) || (nxt != 0 && !vis[i] && flow[i] > flow[nxt]))
					nxt = i;
		}
		if (flow[N] == 0)
			break;
		int u = N;
		while (bef[u] != 0)
		{
			adj[bef[u]][u] -= flow[N];
			adj[u][bef[u]] += flow[N];
			u = bef[u];
		}
		ans += flow[N];
	}
	cout << ans << endl;
}