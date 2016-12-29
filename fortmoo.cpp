#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
int N, M, ans;
set<int> r[205],c[205];
int main()
{
	freopen("fortmoo.in","r",stdin);
	freopen("fortmoo.out","w",stdout);
	cin >> N >> M;
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		string str; cin >> str;
		for (int j = 1; j <= M; ++j)
		{
			if (str[j-1] == 'X')
			{
				r[i].insert(j);
				c[j].insert(i);
				++cnt;
			}
		}
	}
	if (cnt == N*M)
		ans = 0;
	else
		ans = 1;
	for (int rmin = 1; rmin <= N; ++rmin)
		for (int rmax = rmin+1; rmax <= N; ++rmax)
			for (int cmin = 1,cmax = 2; cmax <= M; ++cmax)
				if (c[cmin].find(rmin) != c[cmin].end() || c[cmin].find(rmax) != c[cmin].end() || c[cmin].upper_bound(rmin) != c[cmin].upper_bound(rmax))
					cmin++;
				else if (r[rmin].find(cmax) != r[rmin].end() || r[rmax].find(cmax) != r[rmax].end())
				{
					cmin = cmax+1;
					cmax++;
				}
				else if (c[cmax].find(rmin) == c[cmax].end() && c[cmax].find(rmax) == c[cmax].end() && c[cmax].upper_bound(rmin) == c[cmax].upper_bound(rmax))
					ans = max(ans,(cmax-cmin+1)*(rmax-rmin+1));
	cout << ans << endl;
}