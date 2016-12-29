//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define in1 "data.in"
#define in2 "fairphoto.in"
#define out1 "data.out"
#define out2 "fairphoto.out"

int n;
pair<int,int> > cow[100000];
int sum[100000];
int pref[100000];
int ans;

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		char b;
		fin >> a >> b;
		int c = b == 'W' ? 1 : -1;
		cow[i] = make_pair(a,c);
	}
	sort(cow,cow+n);

	sum[0] = 0;
	pref[0] = cow[i].second;
	for (int i = 1; i < n; ++i)
	{
		sum[i] = cow[i].first-sum[0];
		pref[i] = pref[i-1]+cow[i].second;
	}

	int x = 0;
	int y = n-1;
	while (x < y)
	{
		if (abs(pref[x]-pref[y])%2 == 0)
		{
			ans = sum[y]-sum[x];
			break;
		}
		else if ()
	}

	fin.close();
	fout.close();

	return 0;
}