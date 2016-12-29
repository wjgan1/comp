/*
ID: wgan8561
PROG: stall4
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N, M, ans, flow[500], bef[500], nxt;
bool vis[500];
vector<map<int,int> > v;

int main()
{
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);

	cin >> N >> M;
	v.resize(N+M+5);
	for (int i = 1; i <= N; ++i)
		v[0].insert(make_pair(i,1));
	for (int i = 1; i <= M; ++i)
		v[i+N].insert(make_pair(N+M+1,1));
	for (int i = 1; i <= N; ++i)
	{
		int S; cin >> S;
		for (int j = 0; j < S; ++j)
		{
			int s; cin >> s;
			v[i].insert(make_pair(s+N,1));
		}
	}
	/*
	for (int i = 0; i <= N+M+1; ++i)
	{
		cout << i << ": ";
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	*/
	while (true)
	{
		for (int i = 0; i <= N+M+1; ++i)
		{
			flow[i] = 0;
			vis[i] = false;
			bef[i] = -1;
		}
		flow[0] = 1;
		nxt = 0;
		while (nxt != -1)
		{
			vis[nxt] = true;
			for (map<int,int>::iterator it = v[nxt].begin(); it != v[nxt].end(); ++it)
			{
				int f = min(flow[nxt],it->second), u = it->first;
				if (f > flow[u])
				{
					flow[u] = f;
					bef[u] = nxt;
				}
			}
			nxt = -1;
			for (int i = 0; i <= N+M+1; ++i)
				if ((nxt == -1 && !vis[i] && flow[i] > 0) || (nxt != 0 && !vis[i] && flow[i] > flow[nxt]))
					nxt = i;
		}
		//cout << flow[N+M+1] << endl;
		if (flow[N+M+1] == 0)
			break;
		int u = N+M+1;
		while (bef[u] != -1)
		{
			v[bef[u]][u] -= flow[N+M+1];
			v[u][bef[u]] += flow[N+M+1];
			u = bef[u];
		}
		ans += flow[N+M+1];
	}
	cout << ans << endl;
}