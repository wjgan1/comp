#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1 << 17
#define MAXC 1 << 30
int N, T, ans;
vector<pair<pair<int,int>,int> > endpts;
struct segment
{
	int c1, c2, c3;
	bool h, inserted;
};
segment segs[100005];
struct RangeNode
{
	int val;
	RangeNode* C[2];
	RangeNode()
	{
		val = 0;
		C[0] = C[1] = NULL;
	}
	RangeNode* getC(int c)
	{
		if (!C[c])
			C[c] = new RangeNode();
		return C[c];
	}
	void update(int y, int v, int ns, int ne)
	{
		val += v;
		if (ns >= ne)
			return;
		int mid = (ns+ne)/2;
		if (y <= mid)
			getC(0)->update(y,v,ns,mid);
		else
			getC(1)->update(y,v,mid+1,ne);
	}
	int query(int ns, int ne, int qs, int qe)
	{
		if (ns >= qs && ne <= qe)
			return val;
		if (ns > qe || ne < qs || ns > ne)
			return 0;
		int mid = (ns+ne)/2;
		return (C[0] ? C[0]->query(ns,mid,qs,qe) : 0)+(C[1] ? C[1]->query(mid+1,ne,qs,qe) : 0);
	}
};
RangeNode bit[MAXN];
void bit_update(int idx, int y, int val)
{
	while (idx < MAXN)
	{
		bit[idx].update(y,val,0,MAXC);
		idx += (idx & -idx);
	}
}
int bit_query(int qs, int qe, int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum += bit[idx].query(0,MAXC,qs,qe);
		idx -= (idx & -idx);
	}
	return sum;
}
int main()
{
	freopen("mowing.in","r",stdin);
	freopen("mowing.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> N >> T;
	int xprev, yprev;
	cin >> xprev >> yprev;
	for (int i = 2; i <= N; ++i)
	{
		int x, y; cin >> x >> y;
		if (x == xprev)
		{
			segs[i-1].c1 = min(y,yprev);
			segs[i-1].c2 = max(y,yprev);
			segs[i-1].c3 = x;
			segs[i-1].h = false;
			endpts.push_back(make_pair(make_pair(x,0),i-1));
		}
		else
		{
			segs[i-1].c1 = min(x,xprev);
			segs[i-1].c2 = max(x,xprev);
			segs[i-1].c3 = y;
			segs[i-1].h = true;
			endpts.push_back(make_pair(make_pair(segs[i-1].c1,1),i-1));
			endpts.push_back(make_pair(make_pair(segs[i-1].c2,-1),i-1));
			segs[i-1].inserted = false;
		}
		xprev = x;
		yprev = y;
	}
	sort(endpts.begin(),endpts.end());
	cout << "";
	for (int i = 0; i < endpts.size(); ++i)
	{
		int c = endpts[i].first.first, k = endpts[i].second;
		if (segs[k].h && !segs[k].inserted)
		{
			segs[k].inserted = true;
			bit_update(k,segs[k].c3,1);
		}
		else if (segs[k].h && segs[k].inserted)
		{
			segs[k].inserted = false;
			bit_update(k,segs[k].c3,-1);
		}
		else
			ans += bit_query(segs[k].c1+1,segs[k].c2-1,N)-bit_query(segs[k].c1+1,segs[k].c2-1,min(k+T-1,N))+bit_query(segs[k].c1+1,segs[k].c2-1,max(0,k-T));
	}
	cout << ans << endl;
}