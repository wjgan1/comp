 #include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int N, x[505], y[505], h[1005][1005], g[1005][1005];
bool isH[505];
map<int,int> mx, my;
int main()
{
	freopen("cowrect.in","r",stdin);
	freopen("cowrect.out","w",stdout);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int a, b; char c; cin >> a >> b >> c;
		x[i] = a;
		y[i] = b;
		h[a][b] = c == 'H' ? h[a][b]+1 : h[a][b];
		g[a][b] = c == 'G' ? g[a][b]+1 : g[a][b];
		isH[i] = c == 'H';
		mx[a] = i;
		my[b] = i;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = )
	}
}