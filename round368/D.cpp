#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

struct node {
	vector<int> op;
	vector<node*> c;
	int t, a, b;
	node(int tt, int aa, int bb) {
		t = tt;
		a = aa;
		b = bb;
	}
};

int N, M, Q, tot, cnt[1005], result[100005];
bool invert[1005], book[1005][1005];
node *idx[100005];

void dfs(node *u) {
	bool reverse = false;
	int t = u->t, a = u->a, b = u->b;
	if (t == 1 && book[a][b] == invert[a]) {
		cnt[a]++;
		tot++;
		reverse = true;
		book[a][b] = !invert[a];
	}
	else if (t == 2 && book[a][b] == !invert[a]) {
		cnt[a]--;
		tot--;
		reverse = true;
		book[a][b] = invert[a];
	}
	else if (t == 3) {
		invert[a] = !invert[a];
		tot = tot-cnt[a]+M-cnt[a];
		cnt[a] = M-cnt[a];
	}
	for (int i = 0; i < u->op.size(); ++i)
		result[u->op[i]] = tot;
	for (int i = 0; i < u->c.size(); ++i)
		dfs(u->c[i]);
	if (t == 1 && reverse) {
		cnt[a]--;
		tot--;
		book[a][b] = invert[a];
	}
	else if (t == 2 && reverse) {
		cnt[a]++;
		tot++;
		book[a][b] = !invert[a];
	}
	else if (t == 3) {
		invert[a] = !invert[a];
		tot = tot-cnt[a]+M-cnt[a];
		cnt[a] = M-cnt[a];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> Q;
	node *u = idx[0] = new node(0,0,0);
	for (int i = 1; i <= Q; ++i) {
		int t, a, b;
		cin >> t >> a;
		if (t <= 2)
			cin >> b;
		if (t == 4)
			idx[i] = idx[a];
		else {
			idx[i] = new node(t,a,b);
			u->c.push_back(idx[i]);
		}
		idx[i]->op.push_back(i);
		u = idx[i];
	}
	dfs(idx[0]);
	for (int i = 1; i <= Q; ++i)
		cout << result[i] << endl;
}