#include <iostream>
#include <string>
using namespace std;

int N, arr[100005];
bool vis[100005];

int main() {
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < N; ++i)
		arr[i] = str[i] == '>' ? 1 : -1;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		arr[i] *= x;
	}
	for (int i = 0; ; i += arr[i]) {
		if (i < 0 || i >= N) {
			cout << "FINITE" << endl;
			break;
		}
		if (vis[i]) {
			cout << "INFINITE" << endl;
			break;
		}
		vis[i] = true;
	}
}