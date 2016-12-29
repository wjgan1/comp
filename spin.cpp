/*
ID: wgan8561
PROG: spin
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

vector<pair<int,int> > s;
int w[5][5][2], c[5], v[5];
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);

    for (int i = 0; i < 5; ++i)
    {
    	cin >> v[i] >> c[i];
    	for (int j = 0; j < c[i]; ++j)
    		cin >> w[i][j][0] >> w[i][j][1];
    }

    for (int i = 0; i <= 361; ++i)
    {
    	//cout << endl << i << endl;
    	s.resize(0);
    	for (int j = 0; j < 5; ++j)
    	{
    		for (int k = 0; k < c[j]; ++k)
    		{
    			//cout << w[j][k][0] << " " << w[j][k][0]+w[j][k][1] << endl;
    			s.push_back(make_pair(w[j][k][0],-1));
    			s.push_back(make_pair(w[j][k][0]+w[j][k][1],1));
    			s.push_back(make_pair(w[j][k][0]+360,-1));
    			s.push_back(make_pair(w[j][k][0]+w[j][k][1]+360,1));
    			w[j][k][0] = (w[j][k][0]+v[j])%360;
    		}
    	}
    	sort(s.begin(),s.end());
    	int ps = 0;
    	for (int j = 0; j < s.size(); ++j)
    	{
    		//cout << s[j].first << " " << s[j].second << endl;
    		ps += s[j].second;
    		if (ps <= -5)
    		{
    			cout << i << endl;
    			return 0;
    		}
    	}
    }

    cout << "none" << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}