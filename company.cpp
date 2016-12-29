#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int N, Q, id[200005], sz[200005];
set<int> st;

int par(int x)
{
	if (x == id[x])
		return x;
	return id[x] = par(id[x]);
}

void uni(int x, int y)
{
	int p = par(x);
	int q = par(y);
	if (p == q)
		return;
	if (sz[p] > sz[q])
		id[q] = id[p];
	else if (sz[p] < sz[q])
		id[p] = id[q];
	else
	{
		id[p] = id[q];
		++sz[q];
	}
}

bool find(int x, int y)
{
	return par(x) == par(y);
}

int main()
{

	ios_base::sync_with_stdio(0);
	int merges = 0;
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
	{
		id[i] = i;
		sz[i] = 1;
		st.insert(i);
	}
	for (int i = 0; i < Q; ++i)
	{
		int type; cin >> type;
		int a, b; cin >> a >> b;
		if (type == 3)
		{
			if (find(a,b))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if (type == 2)
		{
			while (true)
			{
				set<int>::iterator it = st.lower_bound(a);
				if (it == st.end()) 
					break;
				int x = *it;
				if (x >= b)
					break;
				uni(x,b);
					st.erase(it);
			}
		}
		else
			uni(a,b);
	}
}