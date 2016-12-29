#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
using namespace std;

int N, ans;
bool card[50005];
vector<int> e1, e2;
set<int> b;

int main()
{
	freopen("cardgame.in","r",stdin);
	//freopen("cardgame.out","w",stdout);

	cin >> N;
	for (int i = 1; i <= N/2; ++i)
	{
		int a; cin >> a;
		card[a] = true;
		e1.push_back(a);
	}
	for (int i = 1; i <= N/2; ++i)
	{
		int a; cin >> a;
		card[a] = true;
		e2.push_back(a);
	}
	//cout << "asdf" << endl;
	for (int i = 1; i <= N; ++i)
		if (!card[i])
			b.insert(i);
	

	sort(e1.begin(),e1.end(),greater<int>());
	sort(e2.begin(),e2.end());
	//cout << "asdf" << endl;
	for (int i = 1; i <= N/2; ++i)
	{
		set<int>::iterator it = b.end();
		it--;
		//cout << *it << endl;
		if (*it > e1[i])
			ans++;
		b.erase(it);
	}
	for (int i = 1; i <= N/2; ++i)
	{
		set<int>::iterator it = b.begin();
		if (*it < e2[i])
			ans++;
		b.erase(it);
	}
	cout << ans << endl;
}