#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	bool ans = false;
	for (int i = 0;i < N; ++i) {
		string str; cin >> str;
		int prev, next;
		cin >> prev >> next;
		if (prev >= 2400 && next > prev)
			ans = true;
	}
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;	
}