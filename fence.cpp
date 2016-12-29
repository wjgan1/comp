/*
ID: wgan8561
PROG: fence
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

int F, T, trail[1030], deg[505], O, p = -1, q = -1;
vector<map<int,int> > f(505);

void dfs(int x)
{
	while (f[x].size() > 0)
	{
		int y = f[x].begin()->first;
		--f[x][y];
		--f[y][x];
		if (f[x][y] == 0)
		{
			f[x].erase(y);
			f[y].erase(x);
		}
		dfs(y);
	}
	trail[T] = x;
	++T;
}
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    cin >> F;
    for (int i = 0; i < F; ++i)
    {
    	int a, b;
    	cin >> a >> b;
    	if (f[a].find(b) != f[a].end())
    		++f[a][b];
    	else
    		f[a].insert(make_pair(b,1));
    	if (f[b].find(a) != f[b].end())
    		++f[b][a];
    	else
    		f[b].insert(make_pair(a,1));
    	++deg[a];
    	++deg[b];
    }

    for (int i = 1; i <= 500; ++i)
    {
    	if (deg[i]%2 == 1)
    	{
    		++O;
    		q = p == -1 ? q : i;
    		p = p == -1 ? i : p;
    	}
    }

    if (O == 2)
    	dfs(min(p,q));
    else
    {
    	for (int i = 1; i <= 500; ++i)
    	if (f[i].size() > 0)
    	{
    		dfs(i);
    		break;
    	}
    }

    for (int i = T-1; i >= 0; --i)
    	cout << trail[i] << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}