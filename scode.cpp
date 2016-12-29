//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=396
//2/15/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "scode.in"
#define out1 "data.out"
#define out2 "scode.out"

int ans;
string str;
vector<pair<string,int> > strs;

void solve(string s)
{
	//cout << "a" << endl;
	for (int i = 0; i < strs.size(); ++i)
	{
		if (s.compare(strs[i].first) == 0)
		{
			ans += strs[i].second;
			return;
		}
	}
	if (s.compare(str) == 0)
		++ans;
	if (s.size() > str.size() || (strs.size() > 0 && s.size() > strs[strs.size()-1].first.size()))
		return;
	//cout << "x" << endl;
	solve(s.substr(0,s.size()-1)+s);
	solve(s+s.substr(0,s.size()-1));
	solve(s.substr(1,s.size()-1)+s);
	solve(s+s.substr(1,s.size()-1));
}

int main()
{
	ifstream fin(in2);
	fin >> str;
	fin.close();

	for (int i = str.size()/2+1; i >= 2; --i)
	{
		for (int j = 0; j <= str.size()-i; ++j)
		{
			//cout << "c" << endl;
			string s = str.substr(j,i);
			bool b = true;
			for (int k = 0; k < strs.size(); ++k)
			{
				if (s.compare(strs[k].first) == 0)
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				int tmp = ans;
				solve(s);
				if (ans > tmp)
					strs.push_back(make_pair(s,ans-tmp));
			}
		}
	}
	
	ofstream fout(out2);
	fout << ans << endl;
	fout.close();

	return 0;
}