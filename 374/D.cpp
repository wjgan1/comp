#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pi;

int N, K, x;
ll arr[200005];
priority_queue<pi> p;

int sign(ll x) {
	return x >= 0 ? 1 : -1;
}

int main() {
	cin >> N >> K >> x;
	int par = 1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			par *= -1;
		p.push(pi(-abs(arr[i]),i));
	}
	for (int k = 1; k <= K; k++) {
		pi best = p.top();
		p.pop();
		int s = sign(arr[best.second]);
		arr[best.second] += par < 0 ? s*x : -s*x;
		par = par/s*sign(arr[best.second]);
		p.push(pair<ll,int>(-abs(arr[best.second]),best.second));
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << endl;
}