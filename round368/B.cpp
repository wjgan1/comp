#include <iostream>
#include <vector>
using namespace std;

typedef pair<pair<int,int>,int> edge;

#define endl '\n'
#define x first
#define y second

int N, M, K, ans = 1 << 30;
vector<edge> e;
bool sto[100005];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		int u, v, l;
		cin >> u >> v >> l;
		e.push_back(make_pair(make_pair(u,v),l)); 
	}
	for (int i = 0; i < K; ++i) {
		int k;
		cin >> k;
		sto[k] = true;
	}
	for (int i = 0; i < M; ++i)
		if ((sto[e[i].x.x] || sto[e[i].x.y]) && !(sto[e[i].x.x] && sto[e[i].x.y]))
			ans = min(ans,e[i].y);
	if (ans == 1 << 30)
		cout << -1 << endl;
	else
		cout << ans << endl;
}