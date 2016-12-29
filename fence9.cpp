/*
ID: wgan8561
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, m, p, ans;
double s1, s2;

int main()
{
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	cin >> n >> m >> p;
	s1 = m*1.0/n;
	if (n <= p)
	{
		for (int i = 1; i < n; ++i)
		{
			double a = s1*i-1;
			if (a-floor(a) <= 0.001)
				a = floor(a);
			ans += ceil(a);
		}
		if (n < p)
		{
			s2 = -1.0*m/(p-n);
			for (int i = max(n,1); i < p; ++i)
			{
				double b = s2*(i-n)+m-1;
				b = b-floor(b) < 0.001 ? floor(b) : b;
				ans += ceil(b;
			}
		}
	}
	else
	{
		for (int i = 1; i <= p; ++i)
			ans += ceil(s1*i-1);
		s2 = m*1.0/(n-p);
		//cout << s2 << endl;
		for (int i = p+1; i < n; ++i)
		{
			double a = s1*i-1;
			if (a-floor(a) <= 0.001)
				a = floor(a);
			double b = s2*(i-p);
			if (ceil(b)-b <= 0.001)
				b = ceil(b);
			//cout << ceil(a) << endl;
			//cout << floor(s2*(i-p)) << endl;
			ans += ceil(a)-floor(b);
			//if (i%50 == 0)
			//	cout << a << endl;
		}
	}
	cout << ans << endl;
}