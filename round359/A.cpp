#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

#define endl '\n'

int N, M;
ll n[5], m[5];
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		n[i%5]++;
	for (int i = 1; i <= M; ++i)
		m[i%5]++;
	ans = 0LL+(n[0]*m[0])+(n[1]*m[4])+(n[2]*m[3])+(n[3]*m[2])+(n[4]*m[1]);
	cout << ans << endl;
}