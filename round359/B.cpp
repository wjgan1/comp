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

int N, a[100005];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	sort(a+1,a+N+1);
	int mex = 1;
	for (int i = 1; i <= N; ++i) {
		if (a[i] >= mex) {
			++mex;
		}
	}
	cout << mex << endl;
}