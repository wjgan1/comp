#include <iostream>
using namespace std;

#define endl '\n'

int n, t;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> t;
	cin >> str;
	int i = 0;
	while (str[i] != '.')
		i++;
	for (int k = i+1, j = 0; k > i && k < str.size() && j < t; k++) {
		if (str[k] >= '5') {
			str.resize(k);
			k -= 1;
			while (true) {
				if (k < 0) {
					str = "1"+str;
					break;
				}
				if (k == i) {
					str.resize(k);
					--k;
				}
				str[k]++;
				if (str[k] <= '9')
					break;
				if (k < i)
					str[k] = '0';
				else
					str.resize(k);
				k--;
			}
			k--;
			j++;
		}
	}
	cout << str << endl;
}