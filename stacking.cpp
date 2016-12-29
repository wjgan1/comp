//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=104
//2/19/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "stacking.in"
#define out1 "data.out"
#define out2 "stacking.out"

#define m_h 25001
#define m_i m_h

int n, m, mh, h[m_h], c_h = 0, hs[m_h];
int ans;
pair<int,int> cmd[2*m_i];

int main()
{
	ifstream fin(in1);
	fin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		fin >> a >> b;
		cmd[i] = make_pair(a,-1);
		cmd[2*m-1-i] = make_pair(b+1,1);
	}
	sort(cmd,cmd+2*m);

	hs[0] = 1;
	for (int i = 0; i < 2*m; ++i)
	{
		h[c_h] += cmd[i].first-hs[c_h];
		if (cmd[i].second == -1)
		{
			++c_h;
			hs[c_h] = cmd[i].first;
			if (c_h > mh)
				mh = c_h;
		}
		else
		{
			--c_h;
			hs[c_h] = cmd[i].first;
		}
	}

	//for (int i = 0; i <= mh; ++i)
	//	cout << h[i] << endl;
	if (h[0] >= n/2+1)
		ans = 0;
	else
	{
		for (int i = 1; i <= mh; ++i)
		{
			h[i] += h[i-1];
			if (h[i] >= n/2+1)
			{
				ans = i;
				break;
			}
		}
	}
	fin.close();
	
	ofstream fout(out1);
	fout << ans << endl;
	fout.close();

	return 0;
}