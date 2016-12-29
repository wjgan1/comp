#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int n, ans = 1 << 30, b, r;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		if (str[i] == 'b' && i%2 == 0)
			b++;
		else if (str[i] == 'r' && i%2 == 1)
			r++;
	ans = min(ans,max(b,r));
	b = 0;
	r = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == 'b' && i%2 == 1)
			b++;
		else if (str[i] == 'r' && i%2 == 0)
			r++;
	ans = min(ans,max(b,r));
	cout << ans << endl;
}