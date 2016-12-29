#include <iostream>
#include <cstdio>
using namespace std;
int T, S, s[1005];
int main() {
	freopen("A-large-practice.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> S;
		string str; cin >> str;
		for (int j = 0; j < str.length(); ++j)
			s[j] = str[j]-'0';
		int stand = 0, ans = 0;
		for (int j = 0; j <= S; ++j) {
			if (stand < j) {
				ans += j-stand;
				stand = j;
			}
			stand += s[j];
		}
		cout << "Case #" << i << ": " << ans << endl;
	}	
}