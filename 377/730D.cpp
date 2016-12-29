#include <iostream>
#include <stack>
using namespace std;

int N, M, day[100005], subj[100005], study[100005], ans = 1 << 30;
bool plan[100005];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> day[i];
	for (int i = 1; i <= M; i++)
		cin >> subj[i];
	int lo = 1, hi = N;
	while (lo <= hi) {
		int days = (lo+hi)/2;
		for (int i = 1; i <= M; i++) {
			study[i] = subj[i];
			plan[i] = false;
		}
		stack<int> s;
		for (int i = days; i > 0; i--) {
			if ((day[i] == 0 || plan[day[i]]) && s.size() > 0)
				--study[s.top()];
			else {
				plan[day[i]] = true;
				s.push(day[i]);
			}
			if (study[s.top()] == 0)
				s.pop();
		}
		bool poss = true;
		for (int i = 1; i <= M; i++) {
			if (study[i] > 0) {
				poss = false;
				break;
			}
		}
		if (poss)
			hi = days-1;
		else
			lo = days+1;
	}
	if (lo > N)
		cout << -1 << endl;
	else
		cout << lo << endl;
}