#include <iostream>
#include <cstdio>
using namespace std;

int N, p[100005], cat;
bool vis[100005];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> p[i];
	for (int i = 1; i <= N; ++i)
	{
		if (i == p[i])
			cat = i;
		else if (i == p[p[i]] && cat == 0)
			cat = -1*i;
	}
	if (cat == 0 || (cat < 0 && N%2 == 1))
	{
		cout << "NO" << endl;
		return 0;
	}
	if (cat > 0)
	{
		cout << "YES" << endl;
		vis[cat] = true;
		for (int i = 1; i <= N; ++i)
		{
			int j = i;
			while (!vis[j])
			{
				cout << cat << " " << j << endl;
				vis[j] = true;
				j = p[j];
			}
		}
		return 0;
	}
	cat *= -1;
	vis[cat] = vis[p[cat]] = true;
	for (int i = 1; i <= N; ++i)
	{
		int j = i, cnt = 0;
		while (!vis[j])
		{
			vis[j] = true;
			j = p[j];
			++cnt;
		}
		if (cnt%2 == 1)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	cout << cat << " " << p[cat] << endl;
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
	vis[cat] = vis[p[cat]] = true;
	for (int i = 1; i <= N; ++i)
	{
		int j = i;
		while (!vis[j])
		{
			cout << cat << " " << j << endl;
			vis[j] = true;
			cat = p[cat];
			j = p[j];
		}
	}
}