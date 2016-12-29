#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int T, D, P, ans;
priority_queue<int> pq;
bool b;

int dfs(int x) {
	if (x <= 2) {
		if (x == 2)
			b = true;
		return 0;
	}
	return 1+dfs(x/2)+dfs(x-x/2);
}

int main() {
	freopen("./Desktop/testdata/B-large-practice.in","r",stdin);
	freopen("./Desktop/testdata/ans.out","w",stdout);
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int special = 0;
		cin >> D;
		for (int j = 0; j < D; ++j) {
			cin >> P;
			pq.push(P);
		}
		ans = pq.top();
		while (true) {
			int x = pq.top();
			pq.pop();
			pq.push(x/2);
			pq.push(x-x/2);
			special++;
			ans = min(special+pq.top(),ans);
			if (pq.top() <= 2)
				break;
		}
		while (!pq.empty())
			pq.pop();
		cout << "Case #" << i << ": " << ans << endl;
	}
}