#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

#define P 1001
#define X 1000007

int N, M, K, lazy[262149];
long long tree[262149], p[100005];
string str;

void update(int n, int ns, int ne, int us, int ue, char u)
{
	long long gsum = p[ne]-p[ns-1];
	if (gsum < 0)
		gsum += X;
	if (lazy[n] != 0)
	{
		if (ns != ne)
			lazy[2*n] = lazy[2*n+1] = lazy[n];
		tree[n] = gsum*lazy[n]%X;
		lazy[n] = 0;
	}
	if (ns > ne || ne < us || ns > ue)
		return;
	if (lazy[n] != 0)
	{
		if (ns != ne)
			lazy[2*n] = lazy[2*n+1] = lazy[n];
		tree[n] = gsum*lazy[n]%X;
		lazy[n] = 0;
	}
	if (ns >= us && ne <= ue)
	{
		tree[n] = gsum*u%X;
		if (ns != ne)
			lazy[2*n] = lazy[2*n+1] = u;
		return;
	}
	int mid = (ns+ne)/2;
	update(2*n,ns,mid,us,ue,u);
	update(2*n+1,mid+1,ne,us,ue,u);
	tree[n] = (tree[2*n]+tree[2*n+1])%X;
}

int query(int n, int ns, int ne, int us, int ue)
{
	long long gsum = p[ne]-p[ns-1];
	if (gsum < 0)
		gsum += X;
	if (lazy[n] != 0)
	{
		if (ns != ne)
			lazy[2*n] = lazy[2*n+1] = lazy[n];
		tree[n] = gsum*lazy[n]%X;
		lazy[n] = 0;
	}
	if (ns > ne || ne < us || ns > ue)
		return 0;
	if (lazy[n] != 0)
	{
		if (ns != ne)
			lazy[2*n] = lazy[2*n+1] = lazy[n];
		tree[n] = gsum*lazy[n]%X;
		lazy[n] = 0;
	}
	if (ns >= us && ne <= ue)
		return tree[n];
	int mid = (ns+ne)/2;
	return (query(2*n,ns,mid,us,ue)+query(2*n+1,mid+1,ne,us,ue))%X;
}

bool periodic(int l, int r, int d)
{
	if (d >= r-l+1 || r-l == 0)
		return true;
	if (r-l+1 <= 2*d)
	{
		long long q1 = query(1,1,N,l,r-d), q2 = query(1,1,N,l+d,r);
		long long gsum = p[d]-p[d-1];
		gsum = gsum < 0 ? gsum+X : gsum;
		q1 = gsum != 0 ? q1*gsum%X : q1;
		if (q1 != q2)
			return false;
	}
	int left = (r-l+1)%d;
	if ((r-l+1)/d%2 == 1)
		left += d;
	if (left != 0)
	{
		long long q1 = query(1,1,N,l,l+left-1), q2 = query(1,1,N,r-left+1,r);
		long long gsum = p[r-left-l+1]-p[r-left-l];
		gsum = gsum < 0 ? gsum+X : gsum;
		q1 = gsum != 0 ? q1*gsum%X : q1;
		if (q1 != q2)
			return false;
	}
	int sz = (r-l+1-left)/2;
	long long q1 = query(1,1,N,l,l+sz-1), q2 = query(1,1,N,l+sz,r-left);
	long long gsum = p[sz]-p[sz-1];
	gsum = gsum < 0 ? gsum+X : gsum;
	q1 = gsum != 0 ? q1*gsum%X : q1;
	if (q1 != q2)
		return false;
	return periodic(l,l+sz-1,d);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	cin >> str;
	p[1] = P;
	for (int i = 2; i <= N; ++i)
		p[i] = p[i-1]*P%X;
	for (int i = 2; i <= N; ++i)
		p[i] = (p[i]+p[i-1]+X)%X;
	for (int i = 1; i <= N; ++i)
		update(1,1,N,i,i,str[i-1]);
	for (int i = 0; i < M+K; ++i)
	{
		int a, l, r, d;
		cin >> a >> l >> r >> d;
		if (a == 1)
			update(1,1,N,l,r,d+48);
		else if (a == 2)
		{
			if (periodic(l,r,d))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}