#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int N, Q;
pair<int,int> xy[100005];
ll disttree[262149], skiptree[262149];

void update1(int n, int ns, int ne, int k, ll val)
{
	if (ns > ne || ns > k || ne < k)
		return;
	if (ns == ne && ns == k)
	{
		disttree[n] = val;
		return;
	}
	int mid = (ns+ne)/2;
	update1(2*n,ns,mid,k,val);
	update1(2*n+1,mid+1,ne,k,val);
	disttree[n] = disttree[2*n]+disttree[2*n+1];
}

void update2(int n, int ns, int ne, int k, ll val)
{
	if (ns > ne || ns > k || ne < k)
		return;
	if (ns == ne && ns == k)
	{
		skiptree[n] = val;
		return;
	}
	int mid = (ns+ne)/2;
	update2(2*n,ns,mid,k,val);
	update2(2*n+1,mid+1,ne,k,val);
	skiptree[n] = max(skiptree[2*n],skiptree[2*n+1]);
}

ll query1(int n, int ns, int ne, int qs, int qe)
{
	if (ns > ne || qs > qe || ns > qe || ne < qs)
		return 0;
	if (ns >= qs && ne <= qe)
		return disttree[n];
	int mid = (ns+ne)/2;
	return query1(2*n,ns,mid,qs,qe)+query1(2*n+1,mid+1,ne,qs,qe);
}

ll query2(int n, int ns, int ne, int qs, int qe)
{
	if (ns > ne || qs > qe || ns > qe || ne < qs)
		return 1 << 31;
	if (ns >= qs && ne <= qe)
		return skiptree[n];
	int mid = (ns+ne)/2;
	return max(query2(2*n,ns,mid,qs,qe),query2(2*n+1,mid+1,ne,qs,qe));
}

int main()
{
	freopen("marathon.in","r",stdin);
	freopen("marathon.out","w",stdout);
	cin >> N >> Q;
	cin >> xy[1].first >> xy[1].second;
	for (int i = 2; i <= N; ++i)
	{
		cin >> xy[i].first >> xy[i].second;
		int range = abs(xy[i].second-xy[i-1].second)+abs(xy[i].first-xy[i-1].first);
		update1(1,1,N-1,i-1,range);
		if (i > 2)
		{
			range += abs(xy[i-1].second-xy[i-2].second)+abs(xy[i-1].first-xy[i-2].first);
			update2(1,1,N-2,i-2,range-(abs(xy[i].second-xy[i-2].second)+abs(xy[i].first-xy[i-2].first)));
		}
	}
	//for (int i = 1; i <= 2*N-3; ++i)
	//	cout << i << " " << disttree[i] << " " << skiptree[i] << endl;
	for (int i = 0; i < Q; ++i)
	{
		char c;
		cin >> c;
		if (c == 'U')
		{
			int k;
			cin >> k;
			cin >> xy[k].first >> xy[k].second;
			int range1, range2;
			if (k > 1)
			{
				range1 = abs(xy[k].second-xy[k-1].second)+abs(xy[k].first-xy[k-1].first);
				update1(1,1,N-1,k-1,range1);
			}
			if (k < N)
			{
				range2 = abs(xy[k].second-xy[k+1].second)+abs(xy[k].first-xy[k+1].first);
				update1(1,1,N-1,k,range2);
			}
			if (k > 1 && k < N)
				update2(1,1,N-2,k-1,range1+range2-(abs(xy[k+1].first-xy[k-1].first)+abs(xy[k+1].second-xy[k-1].second)));
			if (k > 2)
			{
				range1 += abs(xy[k-1].second-xy[k-2].second)+abs(xy[k-1].first-xy[k-2].first);
				update2(1,1,N-2,k-2,range1-(abs(xy[k].second-xy[k-2].second)+abs(xy[k].first-xy[k-2].first)));
			}
			if (k < N-1)
			{
				range2 += abs(xy[k+1].second-xy[k+2].second)+abs(xy[k+1].first-xy[k+2].first);
				update2(1,1,N-2,k,range2-(abs(xy[k].second-xy[k+2].second)+abs(xy[k].first-xy[k+2].first)));
			}
		}
		else
		{
			int a, b;
			cin >> a >> b;
			cout << query1(1,1,N-1,a,b-1)-query2(1,1,N-2,a,b-2) << endl;
		}
	}
}