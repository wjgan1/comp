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
#define in2 "crazy.in"
#define out1 "_data.out"
#define out2 "crazy.out"

int n, c;
set<int> x, y;
int edg[1000][4];
int gr[2001][2001];
int ans, cnt;

void flood(int i, int j)
{
	if (gr[2*i+1][2*j+1] == 2)
		++cnt;
	if (gr[2*i+1][2*j+1] == -1)
		return;
	gr[2*i+1][2*j+1] = -1;
	if (i > 0 && gr[2*i][2*j+1] != 1)
		flood(i-1,j);
	if (i < x.size() && gr[2*i+2][2*j+1] != 1)
		flood(i+1,j);
	if (j > 0 && gr[2*i+1][2*j] != 1)
		flood(i,j-1);
	if (j < y.size() && gr[2*i+1][2*j+2] != 1)
		flood(i,j+1);
}

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		fin >> edg[i][0] >> edg[i][1] >> edg[i][2] >> edg[i][3];
		x.insert(edg[i][0]);
		x.insert(edg[i][2]);
		y.insert(edg[i][1]);
		y.insert(edg[i][3]);
	}
	for (int i = 0; i < n; ++i)
	{
		int a = distance(x.begin(),x.find(edg[i][0]));
		int b = distance(x.begin(),x.find(edg[i][2]));
		int xi = min(a,b);
		int xf = max(a,b);
		a = distance(y.begin(),y.find(edg[i][1]));
		b = distance(y.begin(),y.find(edg[i][3]));
		int yi = min(a,b);
		int yf = max(a,b);
		for (int j = xi; j <= xf; ++j)
			gr[2*j+1][2*yi+1] = 1;
		for (int j = yi; j <= yf; ++j)
			gr[2*xi+1][2*j+1] = 1;

	}
	for (int i = 0; i < c; ++i)
	{
		int xc, yc;
		fin >> xc >> yc;
		xc = distance(x.begin(),x.lower_bound(xc));
		yc = distance(y.begin(),y.lower_bound(yc));
		gr[2*xc+1][2*yc+1] = 2;
	}

	for (int i = 0; i < 2*y.size()+1; ++i)
	{
		for (int j = 0; j < 2*x.size()+1; ++j)
			cout << gr[j][i] << " ";
		cout << endl;
	}
	for (int i = 0; i < x.size(); ++i)
		for (int j = 0; j < y.size(); ++j)
			if(gr[2*i+1][2*j+1] == 2)
			{
				cnt = 0;
				flood(i,j);
				if (cnt > ans)
					ans = cnt;
			}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}