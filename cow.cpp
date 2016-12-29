//foreverbronze
//problem link
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "cow.in"
#define out1 "data.out"
#define out2 "cow.out"

int n;
long c = 0, p_c = 0, t = 0;
long ans = 0;
string str;

int main()
{
	ifstream fin(in2);
	fin >> n;
	fin >> str;
	fin.close();

	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'C')
			++c;
		else if (str[i] == 'O')
		{
			p_c += c;
		}
		else if (str[i] == 'W')
		{
			ans += t;
			ans += p_c;
			t += p_c;
			p_c = 0;
			//cout << ans << endl;
		}
	}
	
	ofstream fout(out2);
	fout << ans << endl;
	fout.close();

	return 0;
}