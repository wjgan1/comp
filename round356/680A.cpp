#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

#define endl '\n'

int t[5], val[105], sm = 0, mx = 0;

int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 5; ++i) {
		cin >> t[i];
		sm += t[i];
		val[t[i]]++;
		if (val[t[i]] >= 3)
			mx = max(mx,t[i]*3);
		else if (val[t[i]] >= 2)
			mx = max(mx,t[i]*2);
	}
	//cout << sm << mx << endl;
	cout << sm-mx << endl;
}