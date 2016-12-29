#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, k, val[200005];
long long dp[2000005][3], ans;
map<int,long long> mp[3];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		scanf("%d",&val[i]);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 2; j > 0; --j)
		{
			if (val[i]%k == 0)
			{
				if (mp[j-1].find(val[i]/k) != mp[j-1].end())
					dp[i][j] = mp[j-1][val[i]/k];
				if (mp[j].find(val[i]) == mp[j].end())
					mp[j][val[i]] = 0;
				mp[j][val[i]] += dp[i][j];
			}
		}
		dp[i][0] = 1;
		if (mp[0].find(val[i]) == mp[0].end())
			mp[0][val[i]] = 0;
		mp[0][val[i]] += 1;
	}

	for (int i = 0; i < n; ++i)
		ans += dp[i][2];

	cout << ans << endl;

	/*
	sort(val,val+n);
	
	for (int i = 1; i < 3; ++i)
	{
		for (int j = 1; j < n; ++j)
			pref[j] = pref[j]+pref[j-1];
		for (int j = n-1; j >= 0; --j)
		{
			pref[j] = 0;
			if (val[j].first%k == 0)
			{
				int c = val[j].first/k;
				if (val[j].first < 0)
					c = val[j].first*k;
				else
					c = val[j].first/k;
				int x = 0;
				int y = j;
				int mid;
				while (x <= y)
				{
					mid = (x+y)/2;
					//cout << mid << " " << val[mid].first << " " << val[mid].second << endl;
					if (val[mid].first == c && val[mid].second == val[j].second)
					{
						//cout << y << endl;
						if (y != mid)
							y -= 2;
						else
							y -= 1;
					}
					else if (val[mid].first < c || (val[mid].first == c && val[mid].second < val[j].second))
						x = mid+1;
					else
						y = mid-1;
				}
				int mid2 = y;
				x = 0;
				y = j;
				while (x <= y)
				{
					mid = (x+y)/2;
					if (val[mid].first == c && val[mid].second == -1)
						break;
					else if (val[mid].first < c || (val[mid].first == c && val[mid].second < -1))
						x = mid+1;
					else
						y = mid-1;
				}
				cout << i << " " << j << " " << mid2 << " " << y << endl;
				if (y >= 0)
					pref[j] = pref[mid2]-pref[y];
				else if (mid2 >= 0)
					pref[j] = pref[mid2];
			}
		}
		
		for (int j = 0; j < n; ++j)
			cout << pref[j] << " ";
		cout << endl;
		
	}

	for (int i = 0; i < n; ++i)
		ans += pref[i];
	
	cout << ans << endl;
	*/
}