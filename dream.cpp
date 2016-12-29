#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
using namespace std;

struct node
{
	int i, j, d, c;
	bool o;
	node(int ii, int jj, int dd, int cost, bool orange)
	{
		i = ii;
		j = jj;
		d = dd;
		c = cost;
		o = orange;
	}
};

int ans = -1;
int N, M, grid[1005][1005];
bool vis[1005][1005];
queue<node> bfs;

int main()
{
	//freopen("dream.in","r",stdin);
	//freopen("dream.out","w",stdout);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> grid[i][j];

	bfs.push(node(1,1,-1,0,false));
	while (!bfs.empty())
	{
		node n = bfs.front();
		bfs.pop();
		if (vis[n.i][n.j])
			continue;
		if (n.i == N && n.j == M)
		{
			ans = n.c;
			break;
		}
		vis[n.i][n.j] = true;
		bool orange;
		if (grid[n.i][n.j] == 4)
			orange = false;
		else if (n.o || grid[n.i][n.j] == 2)
			orange = true;
		else
			orange = false;
		if (grid[n.i][n.j] == 4)
		{
			if (n.d == 0)
			{
				if (n.j > 1 && grid[n.i][n.j-1] != 0)
					bfs.push(node(n.i,n.j-1,n.d,n.c,orange));
			}
			else if (n.d == 1)
			{
				if (n.j < M && grid[n.i][n.j+1] != 0)
					bfs.push(node(n.i,n.j+1,n.d,n.c,orange));
			}
			else if (n.d == 2)
			{
				if (n.i > 1 && grid[n.i-1][n.j] != 0)
					bfs.push(node(n.i-1,n.j,n.d,n.c,orange));
			}
			else if (n.d == 3)
			{
				if (n.i < N && grid[n.i+1][n.j] != 0)
					bfs.push(node(n.i+1,n.j,n.d,n.c,orange));
			}
			continue;
		}
		if (n.j > 1 && grid[n.i][n.j-1] != 0 && (orange || grid[n.i][n.j-1] != 3))
			bfs.push(node(n.i,n.j-1,0,n.c+1,orange));
		if (n.j < M && grid[n.i][n.j+1] != 0 && (orange || grid[n.i][n.j+1] != 3))
			bfs.push(node(n.i,n.j+1,1,n.c+1,orange));
		if (n.i > 1 && grid[n.i-1][n.j] != 0 && (orange || grid[n.i-1][n.j] != 3))
			bfs.push(node(n.i-1,n.j,2,n.c+1,orange));
		if (n.i < N && grid[n.i+1][n.j] != 0 && (orange || grid[n.i+1][n.j] != 3))
			bfs.push(node(n.i+1,n.j,3,n.c+1,orange));
	}
	
	cout << ans << endl;
}