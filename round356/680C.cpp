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

int prime[19] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49}, divi = 0;


int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 19; ++i) {
		cout << prime[i] << endl;
		cout << flush;
		string str; cin >> str;
		if (str == "yes")
			divi++;
		if (divi >= 2) {
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
}