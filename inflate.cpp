/*
ID: wgan8561
PROG: inflate
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
#define in2 "inflate.in"
#define out1 "data.out"
#define out2 "inflate.out"

int n, m, mx[10001], p[10001], t[10001];

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> m >> n;
	for (int i = 0; i < n; ++i)
		fin >> p[i] >> t[i];

	mx[0] = 0;
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j < n; ++j)
			if (i-t[j] >= 0 && p[j]+mx[i-t[j]] > mx[i])
				mx[i] = p[j]+mx[i-t[j]];
		if (mx[i] == 0)
			mx[i] = mx[i-1];
	}

	fout << mx[m] << endl;

	fin.close();
	fout.close();

	return 0;
}