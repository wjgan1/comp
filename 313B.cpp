#include <iostream>
#include <cstdio>
using namespace std;

int a1, b1, a2, b2, a3, b3;

int main()
{
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	if (max(a2,a3) <= a1 && b2+b3 <= b1)
		cout << "YES" << endl;
	else if (max(a2,a3) <= b1 && b2+b3 <= a1)
		cout << "YES" << endl;
	else if (a2+a3 <= a1 && max(b2,b3) <= b1)
		cout << "YES" << endl;
	else if (a2+a3 <= b1 && max(b2,b3) <= a1)
		cout << "YES" << endl;
	else if (max(a2,b3) <= a1 && a3+b2 <= b1)
		cout << "YES" << endl;
	else if (max(a2,b3) <= b1 && a3+b2 <= a1)
		cout << "YES" << endl;
	else if (a2+b3 <= a1 && max(a3,b2) <= b1)
		cout << "YES" << endl;
	else if (a2+b3 <= b1 && max(a3,b2) <= a1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}