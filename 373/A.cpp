#include <iostream>
using namespace std;

#define endl '\n'

int n, x[100];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	if (n == 1) {
		int s; cin >> s;
		if (s == 0)
			cout << "UP" << endl;
		else if (s == 15)
			cout << "DOWN" << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> x[i];
	n -= 1;
	if (x[n] > x[n-1] && x[n] == 15)
		cout << "DOWN" << endl;
	else if (x[n] > x[n-1])
		cout << "UP" << endl;
	else if (x[n] < x[n-1] && x[n] == 0)
		cout << "UP" << endl;
	else
		cout << "DOWN" << endl;
}