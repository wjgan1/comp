#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define in1 "_data.in"
#define in2 "gravity.in"
#define out1 "_data.out"
#define out2 "gravity.out"

typedef pair<pair<int,int>,pair<int,int> > pp;

int n, m;
bool vis[500][500][2];
bool val[500][500];
int cr, cc, dr, dc;
int ans;

void search()
{
	priority_queue<pp> next;
	while (cr >= 0 && cr < n && val[cr][cc])
		++cr;
	if (cr < 0 || cr >= n)
		return;
	--cr;
	next.push(make_pair(make_pair(0,0),make_pair(cr,cc)));
	next.push(make_pair(make_pair(-1,1),make_pair(cr,cc)));
	while (!next.empty())
	{
		pp top = next.top();
		next.pop();
		int r = top.second.first;
		int c = top.second.second;
		int g = top.first.second;
		int f = top.first.first;
		if (!vis[r][c][g] && r >= 0 && r < n && c >= 0 && c < m && val[r][c])
		{
 			vis[r][c][g] = true;
			int i = r;
			int j = c;
			if (i == dr && j == dc)
			{
				//cout << r << " " << c << " " << g << endl;
				ans = -1*f;
				return;
			}
			int x = 0;
			while (i >= 0 && i < n && val[i][j])
			{
				i = g == 0 ? i+1 : i-1;
				if (i < 0 || i >=n || vis[i][j][g])
				{
					x = 1;
					break;
				}
				vis[i][j][g] = true;
				if (i == dr && j == dc)
				{
					//cout << r << " " << c << " " << g << endl;
					ans = -1*f;
					return;
				}
			}
			if (x == 1)
				continue;
			i = g == 0 ? i-1 : i+1;
			//cout << i << " " << j << " " << g << " " << f << endl;
			next.push(make_pair(make_pair(f,g),make_pair(i,j-1)));
			next.push(make_pair(make_pair(f,g),make_pair(i,j+1)));
			next.push(make_pair(make_pair(f-1,1-g),make_pair(i,j)));
		}
	}
}
void dfs(int r, int c, bool grav, int flips)
{
	if (r < 0 || r >= n || c < 0 || c >= m || !val[r][c])
		return;
	if (grav)
	{
		if (vis[r][c][0] <= flips)
			return;
		vis[r][c][0] = flips;
	}
	else
	{
		if (vis[r][c][1] <= flips)
			return;
		vis[r][c][1] = flips;
	}
	int i = r;
	int j = c;
	while (i >= 0 && i < n && val[i][j])
	{
		//cout << i << "-" << j << " ";
		i = grav ? i+1 : i-1;
		if (grav)
		{
			if (vis[i][j][0] < flips)
				return;
			vis[i][j][0] = flips;
		}
		else
		{
			if (vis[i][j][1] < flips)
				return;
			vis[i][j][1] = flips;
		}
	}
	i = grav ? i-1 : i+1;
	if (i == dr && j == dc && flips < ans)
	{
	//	cout << r << " " << c << " " << flips << endl;
		ans = flips;
	}
	//cout << endl;
	dfs(i,j-1,grav,flips);
	dfs(i,j+1,grav,flips);
	dfs(i,j+1,!grav,flips+1);
	dfs(i,j,!grav,flips+1);
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);
	ans = -1;

	fin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vis[i][j][0] = vis[i][j][1] = false;
			char c;
			fin >> c;
			if (c == '#')
				val[i][j] = false;
			else
				val[i][j] = true;
			if (c == 'C')
			{
				cr = i;
				cc = j;
			}
			else if (c == 'D')
			{
				dr = i;
				dc = j;
			}
		}
	}
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << i << j << " ";
		cout << endl;
	}	
	*/
	//cout << "1" << endl;
	search();

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}