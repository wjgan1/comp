#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

ll N, arr[100005], nxt[100005], ans = (1<<31)-1;
map<ll,ll> mp;
bool vis[100005];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	for (int i = 1; i <= 2*N; ++i) {
		int idx = i > N ? i-N : i;
		map<ll,ll>::iterator mit = mp.find(arr[idx]);
		if (mit != mp.end())
			nxt[mit->second%N+1] = idx%N+1;
		mp[arr[idx]] = idx;
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			int cnt = 0;
			int idx = i;
			do {
				vis[idx] = true;
				idx = nxt[idx];
				++cnt;
			}
			while (idx != i);
			ans = min(ans,N-cnt);
		}
	}
	cout << ans << endl;
}