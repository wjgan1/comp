#include <iostream>
using namespace std;

#define endl '\n'

typedef long long ll;

ll n, m;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	n = n*n;
	if (n%2 == 1) {
		if (n <= 1)
			cout << -1 << endl;
		else {
			m = (n-1)/2;
			cout << m << " " << m+1 << endl;
		}
	}
	else {
		if (n <= 4)
			cout << -1 << endl;
		else {
			m = (n-4)/4;
			cout << m << " " << m+2 << endl;
		}
	}
}