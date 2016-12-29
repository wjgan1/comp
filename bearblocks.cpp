#include <iostream>
#include <set>
using namespace std;

int N, h[100005], r[100005], ans = 0;
set<pair<int,int> > st;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> h[i];
	h[0] = h[N-1] = 1;
	for (int i = 0; i < N; ++i)
		st.insert(make_pair(h[i],i));
	while (!st.empty()) {
		int i = st.begin()->second;
		st.erase(make_pair(h[i],i));
		if (i > 0 && st.find(make_pair(h[i-1],i-1)) != st.end() && h[i]+1 < h[i-1]) {
			st.erase(make_pair(h[i-1],i-1));
			h[i-1] = h[i]+1;
			st.insert(make_pair(h[i-1],i-1));
		}
		if (i < N-1 && st.find(make_pair(h[i+1],i+1)) != st.end() && h[i]+1 < h[i+1]) {
			st.erase(make_pair(h[i+1],i+1));
			h[i+1] = h[i]+1;
			st.insert(make_pair(h[i+1],i+1));
		}	
	}
	for (int i = 0; i < N; ++i)
		ans = max(ans,h[i]);
	cout << ans << endl;
}