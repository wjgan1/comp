//foreverbronze

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
#define in2 "perimeter.in"
#define out1 "_data.out"
#define out2 "perimeter.out"

int n;
int minx, miny;
set<pair<int,int> > xy;
set<pair<int,int> > vis;
int ans;

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	minx = miny = 1 << 30;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		fin >> x >> y;
		minx = min(x,minx);
		miny = min(y,miny);
		xy.insert(make_pair(x,y));
	}

	queue<pair<int,int> > tovis;
	tovis.push(make_pair(minx-1,miny));
	while (!tovis.empty())
	{
		pair<int,int> curr = tovis.front();
		tovis.pop();
		if (xy.find(curr) == xy.end() && (vis.size() == 0 || vis.find(curr) == vis.end()))
		{
			vis.insert(curr);
			pair<int,int> nxt1 = make_pair(curr.first-1,curr.second);
			set<pair<int,int> >::iterator res11 = xy.find(nxt1);
			set<pair<int,int> >::iterator res12 = vis.find(nxt1);
			pair<int,int> nxt2 = make_pair(curr.first+1,curr.second);
			set<pair<int,int> >::iterator res21 = xy.find(nxt2);
			set<pair<int,int> >::iterator res22 = vis.find(nxt2);
			pair<int,int> nxt3 = make_pair(curr.first,curr.second-1);
			set<pair<int,int> >::iterator res31 = xy.find(nxt3);
			set<pair<int,int> >::iterator res32 = vis.find(nxt3);
			pair<int,int> nxt4 = make_pair(curr.first,curr.second+1);
			set<pair<int,int> >::iterator res41 = xy.find(nxt4);
			set<pair<int,int> >::iterator res42 = vis.find(nxt4);
			int sub = 0;
			if (res11 != xy.end())
				++sub;
			if (res21 != xy.end())
				++sub;
			if (res31 != xy.end())
				++sub;
			if (res41 != xy.end())
				++sub;
			ans += sub;
			if (sub != 0)
			{
				if (res12 == vis.end())
					tovis.push(nxt1);
				if (res22 == vis.end())
					tovis.push(nxt2);
				if (res32 == vis.end())
					tovis.push(nxt3);
				if (res42 == vis.end())
					tovis.push(nxt4);
			}
			cout << ans << " " << curr.first << " " << curr.second << endl;
		}
	}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}