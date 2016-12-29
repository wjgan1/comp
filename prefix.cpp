/*
ID: wgan8561
PROG: prefix
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
#include <queue>

using namespace std;

#define in1 "data.in"
#define in2 "prefix.in"
#define out1 "data.out"
#define out2 "prefix.out"

#define M 1000007
#define P 3
#define S 101

string s;
int mx;
long long h[200];
int sz[200];
long long pw[13];
int v[200000];
long long sh[200001];
queue<int> tv;

int hext(int h, int nh)
{
	return (P*h+nh+S)%M;
}

/*
void solve(int st)
{
	if (st > mx)
		mx = st;
	if (st > s.size())
		return;
	if (p.size() == 0)
		return;
	for (int i = p.size()-1; i >= 0; --i)
	{
		bool b = true;
		if (st+p[i].size() <= s.size())
		{
			for (int j = 0; j < p[i].size(); ++j)
			{
				if (s[st+j] != p[i][j])
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				solve(st+p[i].size());
			}
		}
	}
}
*/

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> s;
	int it = 0;
	while (s.compare(".") != 0)
	{
		for (int i = 0; i < s.size(); ++i)
			h[it] = hext(h[it],s[i]-'A');
		//if (it == 98)
		//	cout << s << endl;
		sz[it] = s.size();
		++it;
		fin >> s;
	}

	pw[0] = 1;
	for (int i = 1; i <= 11; ++i)
	{
		pw[i] = (pw[i-1]*P)%M;
		//cout << pw[i] << " ";
	}
	//cout << endl;
	/*
	for (int i = 0; i < it; ++i)
	{
		cout << sz[i] << " " << h[i] << endl;
	}
	*/
	s = "";
	string t;
	while (fin >> t)
	{
		s += t;
	}

	for (int i = 1; i <= s.size(); ++i)
		sh[i] = hext(sh[i-1],s[i-1]-'A');
	/*
	for (int i = 1; i <= s.size(); ++i)
		cout << sh[i] << " ";
	cout << endl;
	
	int hsh = (sh[0]*pw[sz[1]])%M;
	int hs2 = (M+sh[2]-hsh)%M;
	cout << hs2 << endl;
	*/
	/*
	cout << h[98] << endl;
	int hsh = (sh[10]*pw[sz[98]])%M;
	int hs2 = (M+sh[20]-hsh)%M;
	cout << hs2 << endl;
	*/

	tv.push(0);
	v[0] = 1;
	while (!tv.empty())
	{
		//cout << tv.front() << endl;
		if (tv.front() > mx)
			mx = tv.front();
		for (int i = 0; i < it; ++i)
		{
			if (tv.front()+sz[i] <= s.size())
			{
				long long hsh = (sh[tv.front()]*pw[sz[i]])%M;
				long long hsh2 = (M+sh[tv.front()+sz[i]]-hsh)%M;
				if (hsh2 == h[i] && v[tv.front()+sz[i]] == 0)
				{
					v[tv.front()+sz[i]] = 1;
					//cout << tv.front()+sz[i] << " " << i << endl;
					tv.push(tv.front()+sz[i]);
				}
			}
		}
		tv.pop();
	}
	fout << mx << endl;

	fin.close();
	fout.close();

	return 0;
}