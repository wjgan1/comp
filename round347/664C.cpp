#include <iostream>
#include <string>
//#include <cmath>
using namespace std;

int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		str = str.substr(4);
		int abbrv = 0;
		int pw = 1;
		for (int j = 0; j < str.length(); ++j) {
			abbrv = abbrv*10+str[j]-'0';
			pw *= 10;
		}
		int F = (pw-10)/9;
		int ans;
		if ((1989+F)%pw <= abbrv)
			ans = (1989+F)/pw*pw+abbrv;
		else
			ans = (1989+F)/pw*pw+pw+abbrv;
		cout << ans << endl;
	}
}