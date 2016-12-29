/*
ID: wgan8561
PROG: job
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, A, B;
vector<int> vA, vB, v;
priority_queue<pair<int,int> > pA;

int main()
{
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	cin >> N >> A >> B;
	for (int i = 0; i < A; ++i)
	{
		int t; cin >> t;
		pA.push(make_pair(-1*t,t));
	}
	for (int i = 0; i < N; ++i)
	{
		vA.push_back(-1*pA.top().first);
		pA.push(make_pair(pA.top().first-pA.top().second,pA.top().second));
		pA.pop();
	}
	vB.resize(B);
	v.resize(B);
	for (int i = 0; i < B; ++i)
		cin >> vB[i];
	cout << vA[N-1] << " ";
	int x = 1, y = 40000;
	while (x <= y)
	{
		int mid = (x+y)/2;
		for (int i = 0; i < B; ++i)
			v[i] = mid;
		int p;
		for (int i = N-1; i >= 0; --i)
		{
			p = -1;
			for (int j = 0; j < B; ++j)
				if (v[j]-vB[j] >= vA[i] && (p == -1 || v[j]-vB[j] < v[p]-vB[p]))
					p = j;
			if (p == -1)
				break;
			v[p] -= vB[p];
		}
		if (p != -1)
		{
			if (y-x == 1)
				y = x;
			else
				y = mid-1;
		}
		else
			x = mid+1;
	}
	cout << x << endl;
}