/*
ID: wgan8561
PROG: ttwo
LANG: C++
*/

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
#define in2 "ttwo.in"
#define out1 "data.out"
#define out2 "ttwo.out"

char gr[10][10];
int fx, fy, fd, cx, cy, cd;

pair<pair<int,int>,int> move(int x, int y, int d)
{
	if (d == 0)
	{
		if ( y <= 0 || gr[x][y-1] == '*') d = (d+1)%4;
		else --y;
	}
	else if (d == 1)
	{
		if ( x >= 9 || gr[x+1][y] == '*') d = (d+1)%4;
		else ++x;
	}
	else if (d == 2)
	{
		if ( y >= 9 || gr[x][y+1] == '*') d = (d+1)%4;
		else ++y;
	}
	else if (d == 3)
	{
		if ( x <= 0 || gr[x-1][y] == '*') d = (d+1)%4;
		else --x;
	}
	return make_pair(make_pair(x,y),d);
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	for (int i = 0; i < 10; ++i)
	{
		string s;
		fin >> s;
		for (int j = 0; j < 10; ++j)
		{
			if (s[j] == '*')
				gr[j][i] = s[j];
			else
				gr[j][i] = '.';
			if (s[j] == 'F')
			{
				fx = j;
				fy = i;
			}
			else if (s[j] == 'C')
			{
				cx = j;
				cy = i;
			}
		}
	}
	/*
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			cout << gr[j][i];
		cout << endl;
	}
	*/
	for (int i = 1; i <= 640001; ++i)
	{
		//cout << fx << " " << fy << " " << cx << " " << cy << endl;
		pair<pair<int,int>,int> p = move(fx,fy,fd);
		fx = p.first.first;
		fy = p.first.second;
		fd = p.second;
		p = move(cx,cy,cd);
		cx = p.first.first;
		cy = p.first.second;
		cd = p.second;
		if (fx == cx && fy == cy)
		{
			fout << i << endl;
			fin.close();
			fout.close();
			return 0;
		}
	}

	fout << 0 << endl;
	fin.close();
	fout.close();

	return 0;
}