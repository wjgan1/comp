#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

#define endl '\n'

int N, a, ans;
bool city[105];


int main() {
	ios::sync_with_stdio(false);
	cin >> N >> a;
	for (int i = 0; i < N; ++i)
		cin >> city[i];
	--a;
	for (int i = 0; a+i < N || a-i >= 0; ++i) {
		//cout << a << i << endl;
		if (a-i < 0 && city[a+i])
			ans++;
		else if (a+i >= N && city[a-i])
			ans++;
		else if (city[a-i] && city[a+i])
			ans += i == 0 ? 1 : 2;
	}
	cout << ans << endl;
}