#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int N, arr[105];
string s;

int main() {
	cin >> N >> s;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'B')
			arr[k]++;
		else if (s[i] == 'W' && i > 0 && s[i-1] == 'B')
			k++;
	}
	if (s[N-1] == 'B')
		k += 1;
	cout << k << endl;
	for (int i = 0; i < k; i++)
		cout << arr[i] << endl;
}