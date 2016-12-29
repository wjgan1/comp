//foreverbronze
//problem link
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "wrongdir.in"
#define out1 "data.out"
#define out2 "wrongdir.out"

int n, x[100001], y[100001], d[100001];
vector<pair<int,int> > v;

int main()
{
	ifstream fin(in1);
	string str;
	fin >> str;
	fin.close();

	n = str.size();
	int dir = 0;
	int xloc = 0;
	int yloc = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'F')
		{
			if (dir == 0) ++yloc;
			else if (dir == 1) ++xloc;
			else if (dir == 2) --yloc;
			else if (dir == 3) --xloc;
		}
		else if (str[i] == 'L') dir = (dir+3)%4;
		else if (str[i] == 'R') dir = (dir+1)%4;
		x[i] = xloc;
		y[i] = yloc;
		d[i] = dir;
	}

	//for (int i = 0; i < n; ++i)
	//	cout << x[i] << " " << y[i] << " " << d[i] << endl;

	int xloc2 = 0;
	int yloc2 = 0;
	for (int i = 0; i < n; ++i)
	{
		xloc = x[n-1];
		yloc = y[n-1];
		xloc2 = x[i];
		yloc2 = y[i];
		//cout << str[i] << endl;
		if (str[i] == 'F')
		{
			if (d[i] == 0)
			{
				--yloc;
				--yloc2;
			}
			else if (d[i] == 1)
			{
				--xloc;
				--xloc2;
			}
			else if (d[i] == 2) 
			{
				++yloc;
				++yloc2;
			}
			else if (d[i] == 3) 
			{
				++xloc;
				++xloc2;
			}
			v.push_back(make_pair(yloc-yloc2+xloc2,xloc2-xloc+yloc2));
			v.push_back(make_pair(yloc2-yloc+xloc2,xloc-xloc2+yloc2));
		}
		else if(str[i] == 'L')
		{
			v.push_back(make_pair(xloc2-xloc+xloc2,yloc2-yloc+yloc2));
			xloc = yloc-yloc2+xloc2;
			yloc = xloc2-xloc+yloc2;
			if (d[i] == 3) ++yloc;
			else if (d[i] == 0) ++xloc;
			else if (d[i] == 1) --yloc;
			else if (d[i] == 2) --xloc;
			v.push_back(make_pair(xloc,yloc));
		}
		else if(str[i] == 'R')
		{
			v.push_back(make_pair(xloc2-xloc+xloc2,yloc2-yloc+yloc2));
			xloc = yloc2-yloc+xloc2;
			yloc = xloc-xloc2+yloc2;
			if (d[i] == 1) ++yloc;
			else if (d[i] == 2) ++xloc;
			else if (d[i] == 3) --yloc;
			else if (d[i] == 0) --xloc;
			v.push_back(make_pair(xloc,yloc));
		}
	}
	sort(v.begin(),v.end());
	int ans = 1;
	cout << v[0].first << " " << v[0].second << endl;
	for (int i = 1; i < v.size(); ++i)
		if ((v[i].first != v[i-1].first || v[i].second != v[i-1].second))
		{
			cout << v[i].first << " " << v[i].second << endl;
			++ans;
		}
	
	ofstream fout(out1);
	fout << ans << endl;
	fout.close();

	return 0;
}