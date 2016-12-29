#include <iostream>
#include <cstdio>
using namespace std;

int N, val[100005], cnt[100005], seen[100005], seen2[100005], seen3[100005];
long long ans, eq, od;
bool odd[100005];

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> val[i];
		++cnt[val[i]];
		odd[val[i]] = !odd[val[i]];
		od = odd[val[i]] ? od+1 : od-1;
	}
	if (N%2 == 0 && od != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (N%2 == 1 && od > 1)
	{
		cout << 0 << endl;
		return 0;
	}
	while (val[eq] == val[N-eq-1] && eq < N)
		++eq;
	if (eq == N)
	{
		cout << 1LL*N*(N-1)/2+N << endl;
		return 0;
	}
	for (int i = 0; i < eq; ++i)
		cnt[val[i]] -= 2;
	ans += eq*eq;
	int mid = N%2 == 0 ? N/2-1 : N/2;
	for (int i = eq; i <= mid; ++i)
	{
		ans += eq+1;
		++seen[val[i]];
		int a = seen[val[i]];
		int b = cnt[val[i]]-seen[val[i]];
		if (cnt[val[i]]%2 == 0 && b < a)
			break;
		if (cnt[val[i]]%2 == 1 && ((b < a && i != mid) || (b <= a+1 && i == mid)))
			break;
	}
	//cout << ans << endl;
	mid = N%2 == 1 ? mid : mid+1;
	for (int i = 0; i <= N; ++i)
		seen[i] = 0;
	for (int i = N-eq-1; i >= mid; --i)
	{
		ans += eq+1;
		++seen[val[i]];
		int a = seen[val[i]];
		int b = cnt[val[i]]-seen[val[i]];
		if (cnt[val[i]]%2 == 0 && b < a)
			break;
		if (cnt[val[i]]%2 == 1 && ((b < a && i != mid) || (b <= a+1 && i == mid)))
			break;
	}
	ans -= 1;
	int eq2 = 0;
	int p, q;
	if (N%2 == 0)
	{
		q = mid;
		p = mid-1;
	}
	else
	{
		p = mid-1;
		q = mid+1;
	}
	while (val[p] == val[q])
	{
		++eq2;
		--p;
		++q;
	}

	for (int i = eq; i <= p; ++i)
	{
		++seen2[val[i]];
		++seen3[val[N-1-i]];
	}
	//cout << ans << endl;
	bool b = true;
	for (int i = 0; i <= N; ++i)
		if (seen2[i] != seen3[i])
			b = false;
	if (b)
		ans += 2*(eq2+1)*(eq+1);
	cout << ans << endl;
}