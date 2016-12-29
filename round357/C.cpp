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

int N;
vector<pair<int,int> > v;
map<int,int> m;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		if (str == "insert") {
			int x; cin >> x;
			v.push_back(make_pair(1,x));
			m[x]++;
		}
		else if (str == "removeMin") {
			if (m.size() == 0) {
				v.push_back(make_pair(1,0));
				m[0]++;
			}	
			v.push_back(make_pair(2,0));
			if (--m.begin()->second == 0)
				m.erase(m.begin());
		}
		else if (str == "getMin") {
			int x; cin >> x;
			if (m.find(x) == m.end()) {
				m[x]++;
				v.push_back(make_pair(1,x));
			}
			while (m.begin()->first != x) {
				for (int j = 0; j < m.begin()->second; ++j)
					v.push_back(make_pair(2,0));
				m.erase(m.begin());
			}
			v.push_back(make_pair(3,x));
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == 1)
			cout << "insert " << v[i].second << endl;
		else if (v[i].first == 2)
			cout << "removeMin" << endl;
		else
			cout << "getMin " << v[i].second << endl;
	}
}