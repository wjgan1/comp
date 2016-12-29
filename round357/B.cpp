#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	unsigned int N; cin >> N;
	for (unsigned int a = 0; a <= N; a += 1234567) {
		for (unsigned int b = 0; a+b <= N; b += 123456) {
			if ((N-a-b)%1234 == 0) {
				cout << "YES" << endl;
				return 0;
			} 
		}
	}
	cout << "NO" << endl;
}