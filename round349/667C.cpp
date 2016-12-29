#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

string str;
set<string> st;
bool dp2[10005], dp3[10005];

int main() {
	cin >> str;
	if (str.size() >= 7) {
		st.insert(str.substr(str.size()-2,2));
		dp2[2] = true;
	}
	if (str.size() >= 8) {
		st.insert(str.substr(str.size()-3,3));
		dp3[3] = true;
	}
	for (int i = str.size()-1; i >= 5; --i) {
		int n = str.size()-i;
		if ((n-2 >= 1 && dp2[n-2] && (str[i] != str[i+2] || str[i+1] != str[i+3]))
			|| (n-2 >= 1 && dp3[n-2])) {
			dp2[n] = true;
			st.insert(str.substr(i,2));
		}
		if ((n-3 >= 1 && dp2[n-3]) || (n-3 >= 1 && dp3[n-3] && (str[i] != str[i+3] 
			|| str[i+1] != str[i+4] || str[i+2] != str[i+5]))) {
			dp3[n] = true;
			st.insert(str.substr(i,3));
		}
	}
	cout << st.size() << endl;
	for (set<string>::iterator sit = st.begin(); sit != st.end(); ++sit)
		printf("%s\n",&((*sit)[0]));
}