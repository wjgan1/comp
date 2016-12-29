#include <iostream>
#include <map>
using namespace std;

typedef map<int,int>::iterator mit;

#define endl '\n'
#define BITS 30

int Q;
map<int,int> mset;

int main() {
	ios::sync_with_stdio(false);
	cin >> Q;
	mset[0] = 1;
	for (int i = 0; i < Q; ++i) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+')
			mset[x]++;
		else if (c == '-' && --mset[x] <= 0)
			mset.erase(x);
		else if (c == '?') {
			mit lo = mset.begin(), hi = --mset.end();
			int p = 1 << (BITS-1), dv = p;
			while (p > 0 && lo != hi) {
				if (x & p) {
					mit it = mset.lower_bound(dv);
					if (it != mset.begin() && (--it)->first >= lo->first) {
						hi = it;
						dv -= p/2;
					}
					else
						dv += p/2;
				}
				else {
					mit it = mset.lower_bound(dv);
					if (it != mset.end() && it->first <= hi->first) {
						lo = it;
						dv += p/2;
					}
					else
						dv -= p/2;
				}
				p /= 2;
			}
			cout << (x^lo->first) << endl;
		}
	}
}