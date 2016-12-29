#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, k, m, a, l;
set<pair<int,int> > lef;

int main()
{
	cin >> n >> k >> a >> m;
	l = (n+1)/(a+1);
	lef.insert(make_pair(0,0));
	lef.insert(make_pair(n+1,l));
	for (int i = 0; i < m; ++i)
	{
		if (l < k)
		{
			cout << i << endl;
			return 0;
		}
		int move;
		scanf("%d", &move);
		set<pair<int,int> >::iterator aft = lef.upper_bound(make_pair(move,0));
		set<pair<int,int> >::iterator bef = --aft;
		++aft;
		l -= aft->second;
		int x = (aft->first-move)/(a+1);
		int b = (move-bef->first)/(a+1);
		int tmp = aft->first;
		lef.erase(aft);
		l += x+b;
		lef.insert(make_pair(tmp,x));
		lef.insert(make_pair(move,b));
	}
	
	if (l < k)
		cout << m << endl;
	else
		cout << -1 << endl;
}