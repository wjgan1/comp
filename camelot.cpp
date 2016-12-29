/*
ID: wgan8561
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char kx;
int R, C, gr[26][30][26][30], cl[780][26][30], ky, ans = 1 << 30, xmin, xmax, ymin, ymax;
bool vis[26][30];
vector<pair<int,int> > kn;
queue<pair<pair<int,int>,int> > q;

int main()
{
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	cin >> C >> R;
	cin >> kx >> ky;
	kx -= 'A'; --ky;
	xmin = max(0,kx-2);
	xmax = min(R-1,kx+2);
	ymin = max(0,ky-2);
	ymax = min(C-1,ky+2);
	char a; int b;
	string line;
	while (cin >> a >> b)
		kn.push_back(make_pair(a-'A',b-1));

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			for (int x = 0; x < R; ++x)
				for (int y = 0; y < C; ++y)
					gr[i][j][x][y] = 1 << 25;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			for (int x = 0; x < R; ++x)
				for (int y = 0; y < C; ++y)
					vis[x][y] = false;
			vis[i][j] = true;
			q.push(make_pair(make_pair(i,j),0));
			while (!q.empty())
			{
				int x = q.front().first.first;
				int y = q.front().first.second;
				int m = q.front().second;
				q.pop();
				gr[i][j][x][y] = m;
				if (x-2 >= 0 && y-1 >= 0 && !vis[x-2][y-1])
				{
					vis[x-2][y-1] = true;
					q.push(make_pair(make_pair(x-2,y-1),m+1));
				}
				if (x-1 >= 0 && y-2 >= 0 && !vis[x-1][y-2])
				{
					vis[x-1][y-2] = true;
					q.push(make_pair(make_pair(x-1,y-2),m+1));
				}
				if (x+2 < R && y-1 >= 0 && !vis[x+2][y-1])
				{
					vis[x+2][y-1] = true;
					q.push(make_pair(make_pair(x+2,y-1),m+1));
				}
				if (x+1 < R && y-2 >= 0 && !vis[x+1][y-2])
				{
					vis[x+1][y-2] = true;
					q.push(make_pair(make_pair(x+1,y-2),m+1));
				}
				if (x-1 >= 0 && y+2 < C && !vis[x-1][y+2])
				{
					vis[x-1][y+2] = true;
					q.push(make_pair(make_pair(x-1,y+2),m+1));
				}
				if (x-2 >= 0 && y+1 < C && !vis[x-2][y+1])
				{
					vis[x-2][y+1] = true;
					q.push(make_pair(make_pair(x-2,y+1),m+1));
				}
				if (x+2 < R && y+1 < C && !vis[x+2][y+1])
				{
					vis[x+2][y+1] = true;
					q.push(make_pair(make_pair(x+2,y+1),m+1));
				}
				if (x+1 < R && y+2 < C && !vis[x+1][y+2])
				{
					vis[x+1][y+2] = true;
					q.push(make_pair(make_pair(x+1,y+2),m+1));
				}
			}
		}
	}

	for (int k = 0; k < kn.size(); ++k)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cl[k][i][j] = gr[kn[k].first][kn[k].second][i][j]+min(abs(kx-i),abs(ky-j))+abs(abs(kx-i)-abs(ky-j));
				for (int x = xmin; x <= xmax; ++x)
				{
					for (int y = ymin; y <= ymax; ++y)
					{
						int newDist = gr[kn[k].first][kn[k].second][x][y]+gr[x][y][i][j]+min(abs(kx-x),abs(ky-y))+abs(abs(kx-x)-abs(ky-y));
						cl[k][i][j] = min(cl[k][i][j],newDist);
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			int dist = 1 << 30;
			for (int k = 0; k < kn.size(); ++k)
			{
				if (gr[i][j][kn[k].first][kn[k].second] < dist)
				{
					cl[i][j] = k;
					dist = gr[i][j][kn[k].first][kn[k].second];
				}
			}
		}
	}
	
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			cout << gr[kn[0].first][kn[0].second][i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			cout << cl[0][i][j] << " ";
		cout << endl;
	}
	*/
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			int cost = 0;
			for (int k = 0; k < kn.size(); ++k)
				cost += gr[i][j][kn[k].first][kn[k].second];
			if (cost >= ans)
				continue;
			int kingDist = min(abs(kx-i),abs(ky-j))+abs(abs(kx-i)-abs(ky-j));
			cost += kingDist;
			ans = min(ans,cost);
			for (int k = 0; k < kn.size(); ++k)
				ans = min(ans,cost-kingDist-gr[i][j][kn[k].first][kn[k].second]+cl[k][i][j]);
			/*
			for (int x = 0; x < R; ++x)
			{
				for (int y = 0; y < C; ++y)
				{
					int newCost = gr[kn[cl[x][y]].first][kn[cl[x][y]].second][x][y]+min(abs(kx-x),abs(ky-y))+abs(abs(kx-x)-abs(ky-y))+gr[i][j][x][y];
					int oldCost = gr[kn[cl[x][y]].first][kn[cl[x][y]].second][i][j]+min(abs(kx-i),abs(ky-j))+abs(abs(kx-i)-abs(ky-j));
					cost = min(cost,cost-oldCost+newCost);
				}
			}
			if (cost < ans)
				cost = ans;
			*/
		}
	}

	cout << ans << endl;
}