//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define in1 "_data.in"
#define in2 "distant.in"
#define out1 "_data.out"
#define out2 "distant.out"

int n, a, b;
char gr[30][30];
long long ans;

void min_path(int x, int y)
{
	//cout << endl;
	long long min[30][30];
	bool vis[30][30];
	priority_queue<pair<int,pair<int,int> > > nxt;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			min[i][j] = 1LL << 60;
			vis[i][j] = false;
		}
	min[x][y] = 0;
	nxt.push(make_pair(0,make_pair(x,y)));
	while(!nxt.empty())
	{
		int cx = nxt.top().second.first;
		int cy = nxt.top().second.second;
		nxt.pop();
		if (!vis[cx][cy])
		{
			//cout << cx << " " << cy << " " << endl;
			//cout << cx << " " << cy << " " << nxt.top().first << endl;
			vis[cx][cy] = true;
			if (cx > 0)
			{
				if (gr[cx-1][cy] != gr[cx][cy] && min[cx][cy]+b < min[cx-1][cy])
				{
					min[cx-1][cy] = min[cx][cy]+b;
					nxt.push(make_pair(-1*min[cx-1][cy],make_pair(cx-1,cy)));
				}
				else if (gr[cx-1][cy] == gr[cx][cy] && min[cx][cy]+a < min[cx-1][cy])
				{
					min[cx-1][cy] = min[cx][cy]+a;
					nxt.push(make_pair(-1*min[cx-1][cy],make_pair(cx-1,cy)));
				}
			}
			if (cy > 0)
			{
				if (gr[cx][cy-1] != gr[cx][cy] && min[cx][cy]+b < min[cx][cy-1])
				{
					min[cx][cy-1] = min[cx][cy]+b;
					nxt.push(make_pair(-1*min[cx][cy-1],make_pair(cx,cy-1)));
				}
				else if (gr[cx][cy-1] == gr[cx][cy] && min[cx][cy]+a < min[cx][cy-1])
				{
					min[cx][cy-1] = min[cx][cy]+a;
					nxt.push(make_pair(-1*min[cx][cy-1],make_pair(cx,cy-1)));
				}
			}
			if (cx < n-1)
			{
				if (gr[cx+1][cy] != gr[cx][cy] && min[cx][cy]+b < min[cx+1][cy])
				{
					min[cx+1][cy] = min[cx][cy]+b;
					nxt.push(make_pair(-1*min[cx+1][cy],make_pair(cx+1,cy)));
				}
				else if (gr[cx+1][cy] == gr[cx][cy] && min[cx][cy]+a < min[cx+1][cy])
				{
					min[cx+1][cy] = min[cx][cy]+a;
					nxt.push(make_pair(-1*min[cx+1][cy],make_pair(cx+1,cy)));
				}
			}
			if (cy < n-1)
			{
				if (gr[cx][cy+1] != gr[cx][cy] && min[cx][cy]+b < min[cx][cy+1])
				{
					min[cx][cy+1] = min[cx][cy]+b;
					nxt.push(make_pair(-1*min[cx][cy+1],make_pair(cx,cy+1)));
				}
				else if (gr[cx][cy+1] == gr[cx][cy] && min[cx][cy]+a < min[cx][cy+1])
				{
					min[cx][cy+1] = min[cx][cy]+a;
					nxt.push(make_pair(-1*min[cx][cy+1],make_pair(cx,cy+1)));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (min[i][j] > ans)
				ans = min[i][j];
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	//pair<int,pair<int,int> > val = make_pair(2,make_pair(1,5));
	//pair<int,pair<int,int> > val2 = make_pair(0,make_pair(1,1));
	fin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> gr[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			min_path(i,j);

	fout << ans << endl;

	fin.close();
	fout.close();

	return 0;
}