#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a, b;

bool recurse(string p, string q)
{
	if (p.size() != q.size())
		return false;
	int S = p.size();
	if (p == q)
		return true;
	if (S == 1 && p != q)
		return false;
	if (p.size()%2 == 1)
		return false;
	return (recurse(p.substr(0,S/2),q.substr(S/2)) && recurse(p.substr(S/2),q.substr(0,S/2))) || (recurse(p.substr(0,S/2),q.substr(0,S/2)) && recurse(p.substr(S/2),q.substr(S/2)));  
}

int main()
{
	cin >> a >> b;
	if (recurse(a,b))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}