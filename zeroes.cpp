#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n;
string str;
vector<char> v;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    
 	cin >> n;
  	cin >> str;

  	for (int i = 0; i < n; ++i)
  	{
  		v.push_back(str[i]);
  		//cout << str[i] << endl;
  		if (v.size() > 1 && v[v.size()-1] != v[v.size()-2])
  			v.resize(v.size()-2);
  	}

  	cout << v.size() << endl;
 
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}