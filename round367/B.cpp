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

int N, x[100005], Q;
map<int,int> idx;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> x[i];
	sort(x,x+N);
	for (int i = 0; i < N; ++i)
		idx[x[i]] = i;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int m;
		cin >> m;
		map<int,int>::iterator mit = idx.upper_bound(m);
		if (mit == idx.begin())
			cout << 0 << endl;
		else
			cout << (--mit)->second+1 << endl;
	}
}