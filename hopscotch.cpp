#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define M 1000000007
typedef unsigned ui;
ui R,C,K,grid[755][755],path[755],tpaths[755];
vector<vector<ui> > seg;
vector<map<ui,ui> > mp;
void update(vector<ui> &tree,int n,int ns,int ne,ui q,ui u)
{
	if (ns > ne || ns > q || ne < q)
		return;
	if (ns == q && ne == q)
	{
		tree[n] = (tree[n]+u)%M;
		return;
	}
	int mid = (ns+ne)/2;
	update(tree,2*n,ns,mid,q,u);
	update(tree,2*n+1,mid+1,ne,q,u);
	tree[n]=(tree[2*n]+tree[2*n+1])%M;
}
ui query(vector<ui> &tree,int n,int ns,int ne,ui q)
{
	if (ns > ne || ns > q || ne < 1)
		return 0;
	if (ns >= 1 && ne <= q)
		return tree[n];
	int mid = (ns+ne)/2;
	return (query(tree,2*n,ns,mid,q)+query(tree,2*n+1,mid+1,ne,q))%M;
}
int main()
{
	freopen("hopscotch.in","r",stdin);
	freopen("hopscotch.out","w",stdout);
	cin >> R >> C >> K;
	seg.resize(K+5);
	mp.resize(K+5);
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> grid[i][j];
			seg[grid[i][j]].push_back(j);
		}
	}
	for (int i = 1; i <= K; ++i)
	{
		if (seg[i].size() == 0)
			continue;
		sort(seg[i].begin(),seg[i].end());
		mp[i][seg[i][0]] = 1;
		for (int j = 1, k = 2; j < seg[i].size(); ++j)
			if (seg[i][j] != seg[i][j-1])
				mp[i][seg[i][j]] = k++;
		seg[i].clear();
		seg[i].resize(4*mp[i].size());
	}
	for (int i = 1; i <= R; ++i)
	{
		int s = 0;
		for (int j = 1; j <= C; ++j)
		{
			int mit = mp[grid[i][j]][j]-1;
			if (mit > 1)
			{
				ui q = query(seg[grid[i][j]],1,1,mp[grid[i][j]].size(),mit);
				path[j] = (M+tpaths[j-1]-q)%M;
			}
			else
				path[j] = tpaths[j-1];
			if (i > 1 && j > 1 && grid[i][j] != grid[1][1])
				path[j] = (path[j]+1)%M;
			cout << path[j] << " ";
		}
		cout << endl;
		for (int j = 1; j <= C; ++j)
		{
			update(seg[grid[i][j]],1,1,mp[grid[i][j]].size(),mp[grid[i][j]][j],path[j]);
			s = (s+path[j])%M;
			tpaths[j] = (tpaths[j]+s)%M;
		}
	}
	cout << path[C] << endl;
}