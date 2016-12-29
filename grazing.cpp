//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=105
//2/19/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "grazing.in"
#define out1 "data.out"
#define out2 "grazing.out"

int v, k, f[5][5];
int ans;

void solve(int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || x1 > 4 || y1 < 0 || y1 > 4 || x2 < 0 || x2 > 4 || y2 < 0 || y2 > 4)
		return;
	//cout << ans << " " << v << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
	if (f[x1][y1] == 1 || f[x2][y2] == 1)
		return;
	//cout << ans << " " << v << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
	if (v == 25-k-1 && x1 == x2 && y1 == y2)
	{
		++ans;
		return;
	}
	if (x1 == x2 && y1 == y2)
		return;
	f[x1][y1] = f[x2][y2] = 1;
	v += 2;
	solve(x1-1,y1,x2-1,y2);
	solve(x1-1,y1,x2+1,y2);
	solve(x1-1,y1,x2,y2-1);
	solve(x1-1,y1,x2,y2+1);
	solve(x1+1,y1,x2-1,y2);
	solve(x1+1,y1,x2+1,y2);
	solve(x1+1,y1,x2,y2-1);
	solve(x1+1,y1,x2,y2+1);
	solve(x1,y1-1,x2-1,y2);
	solve(x1,y1-1,x2+1,y2);
	solve(x1,y1-1,x2,y2-1);
	solve(x1,y1-1,x2,y2+1);
	solve(x1,y1+1,x2-1,y2);
	solve(x1,y1+1,x2+1,y2);
	solve(x1,y1+1,x2,y2-1);
	solve(x1,y1+1,x2,y2+1);
	v -= 2;
	f[x1][y1] = f[x2][y2] = 0;
}

int main()
{
	ifstream fin(in1);
	fin >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		fin >> a >> b;
		//cout << a << " " << b << endl;
		f[a-1][b-1] = 1;
	}
	/*
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cout << f[j][i] << " ";
		cout << endl;
	}
	*/
	fin.close();

	solve(0,0,4,4);
	
	ofstream fout(out1);
	fout << ans << endl;
	fout.close();

	return 0;
}