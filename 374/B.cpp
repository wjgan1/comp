#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N, K, ans, arr[105];
string p;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr[s.size()]++;
	}
	cin >> p;
	int k = 0;
	for (int i = 1; i < p.size(); i++)
		for (int j = 0; j < arr[i]; j++, k++)
			if (k % K == 0 && k != 0)
				ans += 6;
			else
				ans += 1;
	for (int j = 0; j < arr[p.size()]; j++, k++) {
		if (k % K == 0 && k != 0)
				ans += 6;
			else
				ans += 1;
		if (j == 0)
			cout << ans << endl;
	}
	cout << ans << endl;
}