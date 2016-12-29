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
#define in2 "censor.in"
#define out1 "data.out"
#define out2 "censor.out"

string s;
string t;


int main()
{
	ifstream fin(in2);
	fin >> s;
	fin >> t;
	fin.close();
	
	//cout << s << endl;
	//cout << t << endl;
	for (int i = 0; i <= s.size()-t.size(); ++i)
	{
		bool match = true;
		for (int j = i, k = 0; j < i+t.size(); ++j, ++k)
		{
			if (s[j] != t[k])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			//cout << "yes" << endl;
			s = s.substr(0,i)+s.substr(i+t.size(),s.size()-(i+t.size()));
			i -= t.size();
			if (i < 0)
				i = 0;
		}
	}
	ofstream fout(out2);
	fout << s << endl;
	fout.close();

	return 0;
}