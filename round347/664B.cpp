#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string line;
int p = 1, m, n, val[105];
bool pm[105];

int main() {
	getline(cin,line);
	pm[0] = 1;
	//cout << line << endl;
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == '+') {
			pm[p+m] = 1;
			++p;
		}
		else if (line[i] == '-') {
			pm[p+m] = 0;
			++m;
		}
		else if (line[i] >= '0' && line[i] <= '9')
			n = n*10+(line[i]-'0');
	}
	//cout << n << endl;
	if (n >= p-m*n && n <= p*n-m) {
		cout << "Possible" << endl;
		int sum = p-m;
		for (int i = 0; i < p+m; ++i) {
			if (sum < n && pm[i]) {
				val[i] = min(n-(sum-1),n);
				sum += val[i]-1;
			}
			else if (sum > n && !pm[i]) {
				val[i] = min((sum+1)-n,n);
				sum -= val[i]-1;
			}
			else
				val[i] = 1;
		}
		cout << val[0] << " ";
		for (int i = 1; i < p+m; ++i) {
			if (pm[i])
				cout << "+ ";
			else
				cout << "- ";
			cout << val[i] << " ";
		}
		cout << "= " << n << endl;
	}
	else
		cout << "Impossible" << endl;
}