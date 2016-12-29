/*
ID: wgan8561
PROG: zerosum
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
#define in2 "zerosum.in"
#define out1 "data.out"
#define out2 "zerosum.out"

int n;
char sn[9];
vector<vector<char> > ans;

void check()
{
	int ps = 0;
	for (int i = 1; i <= n; ++i)
	{
		int s = i;
		int j = i;
		while (sn[j] == ' ')
		{
			s = 10*s+(j+1);
			++j;
		}
		if (sn[i-1] == '+')
			ps += s;
		else if (sn[i-1] == '-')
			ps -= s;
		i = j;
	}
	/*
	cout << ps << ": ";
	for (int i = 1; i < n; ++i)
		cout << sn[i] << " ";
	cout << endl;
	*/
	if (ps == 0)
	{
		vector<char> v(2*n-1);
		for (int i = 0; i < n; ++i)
			v[2*i] = i+49;
		for (int i = 1; i < n; ++i)
			v[2*i-1] = sn[i];
		ans.push_back(v);
	}
}

void solve(int i)
{
	if (i >= n)
	{
		check();
		return;
	}
	sn[i] = '+';
	solve(i+1);
	sn[i] = '-';
	solve(i+1);
	sn[i] = ' ';
	solve(i+1);
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;
	sn[0] = '+';

	solve(1);
	sort(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
			fout << ans[i][j];
		fout << endl;
	}

	fin.close();
	fout.close();

	return 0;
}