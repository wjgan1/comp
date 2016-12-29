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
#define in2 "paint.in"
#define out1 "_data.out"
#define out2 "paint.out"

int n, k;
vector<pair<int,int> > ivl;
int ans;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> k;
	int pos = 0;
	for (int i = 0; i < n; ++i)
	{
		int mov;
		char dir;
		fin >> mov >> dir;
		int newpos = 0;
		if (dir == 'R')
			newpos = pos+mov;
		else
			newpos = pos-mov;
		ivl.push_back(make_pair(min(pos,newpos),1));
		ivl.push_back(make_pair(max(pos,newpos),-1));
		pos = newpos;
	}
	sort(ivl.begin(),ivl.end());

	//for (int i = 0; i < ivl.size(); ++i)
	//	cout << ivl[i].first << " " << ivl[i].second << endl;

	int pref = 0;
	for (int i = 0; i < ivl.size()-1; ++i)
	{
		pref += ivl[i].second;
		if (pref >= k)
			ans += ivl[i+1].first-ivl[i].first;

	}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}