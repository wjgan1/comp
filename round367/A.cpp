#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	int N;
	double x0, y0, ans = 1e10;
	cin >> x0 >> y0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		double x, y, v;
		cin >> x >> y >> v;
		double t = ((y-y0)*(y-y0)+(x-x0)*(x-x0))/v;
		ans = min(ans,sqrt((y-y0)*(y-y0)+(x-x0)*(x-x0))/v);
	}
	printf("%.8f\n",ans);
}