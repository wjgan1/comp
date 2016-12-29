#include <iostream>
#include <set>
using namespace std;

int N;
set<pair<int,int> > st;

int main() {
	cin >> N;
	int a; cin >> a;
	st.insert(make_pair(a,1));
	for (int i = 2; i <= N; ++i) {
		cin >> a;
		set<pair<int,int> >::iterator it = st.lower_bound(make_pair(a,0));
		int v1 = -1, v2 = -1, d1 = -1, d2 = -1;
		if (it != st.begin()) {
			v1 = (--it)->first;
			d1 = it->second;
			if ((++it) != st.end()) {
				v2 = it->first;
				d2 = it->second;
			}
		}
		else {
			v2 = it->first;
			d2 = it->second;
		}
		if (d2 > d1) {
			st.insert(make_pair(a,d2+1));
			cout << v2 << endl;
		}
		else {
			st.insert(make_pair(a,d1+1));
			cout << v1 << endl;
		}
	}
}