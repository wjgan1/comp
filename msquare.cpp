/*
ID: wgan8561
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct sq
{
	int arr[8];
	bool operator<(const sq &x)const
    {
    	for (int i = 0; i < 8; ++i)
    		if (arr[i] < x.arr[i])
    			return true;
    		else if (x.arr[i] < arr[i])
    			return false;
    	return false;
    }
    bool operator==(const sq &x)const
    {
    	for (int i = 0; i < 8; ++i)
    		if (arr[i] != x.arr[i])
    			return false;
    	return true;
    }
};

sq tg, init;
set<sq> st;
priority_queue<pair<int,pair<vector<char>,sq> > > pq;

int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    for (int i = 0; i < 8; ++i)
    {
    	cin >> tg.arr[i];
    	init.arr[i] = i+1;
    }

    if (tg == init)
    {
    	cout << 0 << endl << endl;
    	return 0;
    }

    st.insert(init);
    pq.push(make_pair(0,make_pair(vector<char>(),init)));

    while (!pq.empty())
    {
    	pair<int,pair<vector<char>,sq> > tp = pq.top();
    	sq cfg = tp.second.second;
    	int tr = tp.first;
    	vector<char> str = tp.second.first;
    	pq.pop();
   
    	for (int i = 0; i < 4; ++i)
		{
			int tmp = cfg.arr[i];
			cfg.arr[i] = cfg.arr[7-i];
			cfg.arr[7-i] = tmp;
		}
		if (st.find(cfg) == st.end())
		{
			str.push_back('d'-'A');
			if (cfg == tg)
			{
				cout << -1*(tr-1) << endl;
				for (int i = 0; i < str.size(); ++i)
				{
					char c = 'd'-str[i];
					cout << c;
				}
				cout << endl;
				return 0;
			}
			pair<int,pair<vector<char>,sq> > tmpsq = make_pair(tr-1,make_pair(str,cfg));
			st.insert(cfg);
			pq.push(tmpsq);
			str.resize(str.size()-1);
		}
		
		cfg = tp.second.second;
		int tmp = cfg.arr[3];
		for (int i = 3; i > 0; --i)
			cfg.arr[i] = cfg.arr[i-1];
		cfg.arr[0] = tmp;
		tmp = cfg.arr[4];
		for (int i = 4; i < 7; ++i)
			cfg.arr[i] = cfg.arr[i+1];
		cfg.arr[7] = tmp;
		if (st.find(cfg) == st.end())
		{
			str.push_back('d'-'B');
			if (cfg == tg)
			{
				cout << -1*(tr-1) << endl;
				for (int i = 0; i < str.size(); ++i)
				{
					char c = 'd'-str[i];
					cout << c;
				}
				cout << endl;
				return 0;
			}
			pair<int,pair<vector<char>,sq> > tmpsq = make_pair(tr-1,make_pair(str,cfg));
			st.insert(cfg);
			pq.push(tmpsq);
			str.resize(str.size()-1);
		}

		cfg = tp.second.second;
		tmp = cfg.arr[1];
		cfg.arr[1] = cfg.arr[6];
		cfg.arr[6] = cfg.arr[5];
		cfg.arr[5] = cfg.arr[2];
		cfg.arr[2] = tmp;
		if (st.find(cfg) == st.end())
		{
			str.push_back('d'-'C');
			if (cfg == tg)
			{
				cout << -1*(tr-1) << endl;
				for (int i = 0; i < str.size(); ++i)
				{
					char c = 'd'-str[i];
					cout << c;
				}
				cout << endl;
				return 0;
			}
			pair<int,pair<vector<char>,sq> > tmpsq = make_pair(tr-1,make_pair(str,cfg));
			st.insert(cfg);
			pq.push(tmpsq);
			str.resize(str.size()-1);
		}
    }
    
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}