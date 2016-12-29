#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int> > x, y;
long long ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int xx, yy;
		cin >> xx >> yy;
		x.push_back(make_pair(xx,yy));
		y.push_back(make_pair(yy,xx));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	long long cnsq = 1;
	for (int i = 1; i < N; ++i) {
		if (x[i-1].first == x[i].first) {
			cnsq++;
		}
		else {
			ans += cnsq*(cnsq-1)/2;
			cnsq = 1;
		}
	}
	ans += cnsq*(cnsq-1)/2;
	//cout << ans << endl;
	cnsq = 1;
	for (int i = 1; i < N; ++i) {
		if (y[i-1].first == y[i].first) {
			cnsq++;
		}
		else {
			ans += cnsq*(cnsq-1)/2;
			cnsq = 1;
		}
	}
	ans += cnsq*(cnsq-1)/2;
	cnsq = 1;
	for (int i = 1; i < N; ++i) {
		if (x[i-1].first == x[i].first && x[i-1].second == x[i].second) {
			cnsq++;
		}
		else {
			ans -= cnsq*(cnsq-1)/2;
			cnsq = 1;
		}
	}
	ans -= cnsq*(cnsq-1)/2;
	cout << ans << endl;
}