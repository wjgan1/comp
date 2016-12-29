/*
ID: wgan8561
PROG: castle
LANG: C++
*/

//foreverbronze
//2/14/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "castle.in"
#define out1 "data.out"
#define out2 "castle.out"

#define _i 2*i+1
#define _j 2*j+1

int n, m, c[101][101];
int sz, m_sz, n_r, x, y;
char d;

void calc_sz(int i, int j)
{
	if (c[_i][_j] == 1)
		return;
	c[_i][_j] = 1;
	++sz;
	if (i > 0 && c[_i-1][_j] == -1)
		calc_sz(i-1,j);
	if (i < n-1 && c[_i+1][_j] == -1)
		calc_sz(i+1,j);
	if (j > 0 && c[_i][_j-1] == -1)
		calc_sz(i,j-1);
	if (j < m-1 && c[_i][_j+1] == -1)
		calc_sz(i,j+1);
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> m;
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			fin >> tmp;
			c[_i][_j+1] = tmp-8 >= 0 ? 1 : -1;
			tmp = tmp-8 >= 0 ? tmp-8 : tmp;
			c[_i+1][_j] = tmp-4 >= 0 ? 1 : -1;
			tmp = tmp-4 >= 0 ? tmp-4 : tmp;
			c[_i][_j-1] = tmp-2 >= 0 ? 1 : -1;
			tmp = tmp-2 >= 0 ? tmp-2 : tmp;
			c[_i-1][_j] = tmp-1 >= 0 ? 1 : -1;
			tmp = tmp-1 >= 0 ? tmp-1 : tmp;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (c[_i][_j] == 0)
			{
				sz = 0;
				calc_sz(i,j);
				++n_r;
				if (sz > m_sz)
					m_sz = sz;
			}
		}
	}
	fout << n_r << endl << m_sz << endl;
	m_sz = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = m-1; j >= 0; --j)
		{
			if (c[_i][_j-1] == 1)
			{
				for (int k = 0; k < n; ++k)
					for (int l = 0; l < m; ++l)
						c[2*k+1][2*l+1] = 0;
				sz = 0;
				c[_i][_j-1] = -1;
				calc_sz(i,j);
				if (sz > m_sz)
				{
					m_sz = sz;
					x = i+1;
					y = j+1;
					d = 'N';
				}
				c[_i][_j-1] = 2;
			}
			if (c[_i+1][_j] == 1)
			{
				for (int k = 0; k < n; ++k)
					for (int l = 0; l < m; ++l)
						c[2*k+1][2*l+1] = 0;
				sz = 0;
				c[_i+1][_j] = -1;
				calc_sz(i,j);
				if (sz > m_sz)
				{
					m_sz = sz;
					x = i+1;
					y = j+1;
					d = 'E';
				}
				c[_i+1][_j] = 2;
			}
		}
	}

	fout << m_sz << endl << y << " " << x << " " << d << endl;
	fout.close();

	return 0;
}