#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll x[50005], l[50005], r[50005], ans = 1LL << 50;
map<ll,int> xmap;
int main()
{
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> x[i];
		x[i] *= 10;
	}
	sort(x+1,x+N+1);
	for (int i = 1; i <= N; i++)
		xmap[x[i]] = i;
	l[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		map<ll,int>::iterator mit = xmap.lower_bound(x[i]-l[i-1]);
		l[i] = max(x[i]-x[i-1],l[mit->second]+10);
	}
	r[N] = 0;
	for (int i = N-1; i >= 1; i--)
	{
		map<ll,int>::iterator mit = xmap.upper_bound(x[i]+r[i+1]);
		r[i] = max(x[i+1]-x[i],r[mit->second-1]+10);
	}
	ll rmin = 0, rmax = (x[N]-x[1])/2+1, rmid, pmin, pmax, pmid;
	while (rmin <= rmax)
	{
		rmid = (rmin+rmax)/2;
		bool works = false;
		pmin = x[1], pmax = x[N];
		while (pmin <= pmax)
		{
			pmid = (pmin+pmax)/2;
			map<ll,int>::iterator mit = xmap.lower_bound(pmid-rmid);
			bool left = l[mit->second]+10 <= rmid ? 1 : 0;
			mit = xmap.upper_bound(pmid+rmid);
			bool right = r[mit->second-1]+10 <= rmid ? 1 : 0;
			if (!left && !right)
				break;
			if (left && right)
			{
				works = true;
				break;
			}
			if (left)
				pmin = pmid+1;
			else
				pmax = pmid-1;
		}
		if (works)
		{
			ans = min(ans,rmid);
			rmax = rmid-1;
		}
		else
			rmin = rmid+1;
	}
	double ansf = ans/10.0;
	printf("%.1f\n",ansf);
}