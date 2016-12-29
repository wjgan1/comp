/*
ID: wgan8561
PROG: fence6
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N, V, id[210], mat[105][105], dist[210], vis[210], ans = 1 << 30;
map<int,int> keys;
map<int,int> len;
vector<vector<pair<int,int> > > adj;
priority_queue<pair<int,pair<int,int> > > pq;

int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int u, v, length, n1, n2;
		cin >> u >> length >> n1 >> n2;
		len[u] = length;
		for (int j = 0; j < n1; ++j)
		{
			cin >> v;
			mat[u][v] = 1;
		}
		for (int j = 0; j < n2; ++j)
		{
			cin >> v;
			mat[u][v] = 2;
		}
	}
	for (int i = 0; i < 2*N; ++i)
		id[i] = i;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (mat[i][j] != 0)
				id[2*(i-1)+mat[i][j]-1] = id[2*(j-1)+mat[j][i]-1] = min(id[2*(i-1)+mat[i][j]-1],id[2*(j-1)+mat[j][i]-1]);
	for (int i = 0, j = 0; i < 2*N; ++i)
		if (keys.find(id[i]) == keys.end())
			keys.insert(make_pair(id[i],j++));
	adj.resize(keys.size());
	for (int i = 0; i < N; ++i)
	{
		adj[keys[id[2*i]]].push_back(make_pair(keys[id[2*i+1]],len[i+1]));
		adj[keys[id[2*i+1]]].push_back(make_pair(keys[id[2*i]],len[i+1]));
	}
	
	for (int i = 0; i < adj.size(); ++i)
	{
		for (int j = 0; j < adj.size(); ++j)
		{
			dist[j] = 1 << 30;
			vis[j] = false;
		}
		pq.push(make_pair(0,make_pair(i,-1)));
		while (!pq.empty())
		{
			int d = pq.top().first;
			int v = pq.top().second.first;
			int pv = pq.top().second.second;
			pq.pop();
			if (!vis[v])
			{
				vis[v] = true;
				dist[v] = d*-1;
				for (int j = 0; j < adj[v].size(); ++j)
					if (!vis[adj[v][j].first])
						pq.push(make_pair(d-adj[v][j].second,make_pair(adj[v][j].first,v)));
					else if (pv != adj[v][j].first)
						ans = min(ans,dist[v]+dist[adj[v][j].first]+adj[v][j].second);
			}
		}
	}
	cout << ans << endl;
}