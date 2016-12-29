//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define in1 "_data.in"
#define in2 "painting.in"
#define out1 "_data.out"
#define out2 "painting.out"

typedef pair<int,int> pp;

int n;
vector<pair<pair<int,int>,int> > vec;
set<pp> swp;
int ans;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;
	ans = n;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		fin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(x1,y2),-3));
		vec.push_back(make_pair(make_pair(x2,y2),-4));
		vec.push_back(make_pair(make_pair(x1,y1),-1));
		vec.push_back(make_pair(make_pair(x2,y1),-2));
		vec.push_back(make_pair(make_pair(x2,y2),0));
	}
	sort(vec.begin(),vec.end());
	//for (int i = 0; i < vec.size(); ++i)
	//	cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second << endl;

	for (int i = 0; i < vec.size(); ++i)
	{
		//if (vec[i].first.second == 158)
		//	cout << "asdf " << i << endl;
		if (vec[i].second == -3)
			swp.insert(make_pair(vec[i].first.second,1));
		else if (vec[i].second == -4)
			swp.erase(make_pair(vec[i].first.second,1));
		else if (vec[i].second == -1)
			swp.insert(make_pair(vec[i].first.second,0));
		else if (vec[i].second == -2)
			swp.erase(make_pair(vec[i].first.second,0));
		else if (vec[i].second == 0)
		{
			set<pair<int,int> >::iterator it = swp.lower_bound(make_pair(vec[i].first.second,-1));
			int asdf = 0;
			for (; it != swp.end(); ++it)
			{
				if (it->second == 0)
					--asdf;
				else
					++asdf;
				if (asdf > 0)
					break;
			}
			if (asdf > 0)
			{
				//if (it->first == 158)
			//		cout << i << endl;
				//cout << vec[i].first.first << " " << vec[i].first.second << " " << it->first << " " << it->second << endl;
				--ans;
			}
		}
	}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}