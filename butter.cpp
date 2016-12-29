/*
ID: wgan8561
PROG: butter
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

bool vis[805];
int N, P, C, dist[805], ANS = 1 << 30;
vector<int> occ;
vector<vector<pair<int,int> > > adj;
priority_queue<pair<int,int> > pq;

int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);

    cin >> N >> P >> C;
    occ.resize(N);
    adj.resize(P+5);
    for (int i = 0; i < N; ++i)
    	cin >> occ[i];
    for (int i = 0; i < C; ++i)
    {
    	int a, b, c;
    	cin >> a >> b >> c;
    	adj[a].push_back(make_pair(b,c));
    	adj[b].push_back(make_pair(a,c));
    }

    for (int i = 1; i <= P; ++i)
    {
    	for (int j = 1; j <= P; ++j)
    	{
    		dist[j] = 1 << 30;
    		vis[j] = false;
    	}
    	pq.push(make_pair(0,i));
    	while (!pq.empty())
    	{
    		pair<int,int> v = pq.top();
    		pq.pop();
    		if (!vis[v.second])
    		{
    			vis[v.second] = true;
    			dist[v.second] = v.first;
    			for (int j = 0; j < adj[v.second].size(); ++j)
    				pq.push(make_pair(v.first-adj[v.second][j].second,adj[v.second][j].first));
    		}
    	}
    	int sum = 0;
    	for (int j = 0; j < occ.size(); ++j)
    		sum += dist[occ[j]];
    	sum *= -1;
    	if (sum < ANS)
    		ANS = sum;
    }

 	cout << ANS << endl;

 	fclose(stdin);
 	fclose(stdout);
    return 0;
}