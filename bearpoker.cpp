#include <iostream>
using namespace std;

int N, bid[100005];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> bid[i];
	for (int i = 0; i < N; ++i) {
		while (bid[i] % 2 == 0)
			bid[i] /= 2;
		while (bid[i] % 3 == 0)
			bid[i] /= 3;
		if (i > 0 && bid[i] != bid[i-1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}