#include <iostream>
using namespace std;

#define endl '\n'

int N, M;
bool colored;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			if (c == 'C' || c == 'M' || c == 'Y')
				colored = true;
		}
	}
	if (colored)
		cout << "#Color" << endl;
	else
		cout << "#Black&White" << endl;
}