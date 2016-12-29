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
#define in2 "stampede.in"
#define out1 "data.out"
#define out2 "stampede.out"

int n, ans;
vector<int,int> evt;
set<int> act;

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		int pos, h, s;
		fin >> pos >> h >> s;
		double d = -1.0*pos*s;
		val.push_back(make_pair(make_pair(d,-1),h));
		d = -1.0*(pos+1)*s;
		val.push_back(make_pair(make_pair(d,1),h));
	}
	sort(val.begin(),val.end());

	for (int i = 0; i < val.size(); ++i)
		cout << val[i].first.first << " " << val[i].first.second << " " << val[i].second << endl;

	int min = 1 << 30;
	for (int i = 0; i < val.size(); ++i)
	{
		if (val[i].first.second == 1)
		{
			if (val[i].second < min)
			{
				++ans;
				min = val[i].second;
			}
			inset.push_back(val[i].second);
		}
		else
		{
			int nxt = 1 << 30;
			if (val[i].second == min)
				nxt = -1;
			for (int i = 0; i < inset.size(); ++i)
			{
				if (inset[i] != min && inset[i] < nxt)
					nxt = inset[i];
				if (inset[i] == val[i].second)
				{
					inset.erase(inset.begin()+i);
					--i;
					if (nxt == -1)
						break;
				}
			}
			if (nxt != -1)
			{
				++ans;
				min = nxt;
			}
		}
	}

	fout << ans << endl;

	fin.close();
	fout.close();

	return 0;
}