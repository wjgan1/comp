//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=96
//2/19/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "escape.in"
#define out1 "data.out"
#define out2 "escape.out"

#define m_d 9 //max digits in weight
#define m_n 20 //max cows

int n, w[m_n][m_d]; //weights for each cow
int s[m_n]; //cows to use for each selection
int m_r; //max group

void c_w(int r) // calculates weight
{
	int m; //max digit length
	for (int i = 0; i < r; ++i)
		if (w[s[i]][0]-1 > m)
			m = w[s[i]][0]-1;
	bool c = false; //carry?
	for (int i = 0; i < m; ++i)
	{
		int d_s = 0; //digit sum;
		for (int j = 0; j < r; ++j)
			d_s += w[s[j]][i+1];
		if (d_s >= 10)
		{
			c = true;
			break;
		}
	}
	if (!c && r > m_r)
		m_r = r;
}

void g_c(int r, int s_i, int w_i) //how many to choose, index in selection array, index in weight array
{
	if (s_i == r)
		c_w(r);
	for (int i = w_i; i < n; ++i)
	{
		s[s_i] = i;
		g_c(r,s_i+1,i+1);
	}
	s[s_i] = 0;
}

int main()
{
	ifstream fin(in1);
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a; fin >> a;
		int h_p = (int)log10(a); //highest power
		w[i][0] = h_p+2; //for reference
		for (int j = h_p; j >= 0; --j)
		{
			int p = pow(10,j); //p power
			int b = (int)(a/pow(10,j)); //jth digit
			w[i][j+1] = b;
			a = a-b*p;
		}
	}
	fin.close();
	/*
	for(int i = 0; i < n; ++i)
	{
		for (int j = 1; j < w[i][0]; ++j)
			cout << w[i][j] << " ";
		cout << endl;
	}
	*/

	for (int i = 1; i <= n; ++i)
	{
		g_c(i,0,0);
	}

	ofstream fout(out1);
	fout << m_r << endl;
	fout.close();

	return 0;
}