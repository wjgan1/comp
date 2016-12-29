//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define in1 "_data.in"
#define in2 "clumsy.in"
#define out1 "_data.out"
#define out2 "clumsy.out"

int n, prf[100001], sft, chg;
int cls;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	string s;
	fin >> s;
	n = s.size();
	for (int i = 1; i <= n; ++i)
	{
		if (s[i-1] == '(')
			prf[i] = prf[i-1]+1;
		else
		{
			prf[i] = prf[i-1]-1;
			++cls;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (prf[i] < prf[i-1])
			--cls;
		if (prf[i]-sft > cls)
		{
			++chg;
			sft += 2;
		}
		else if (prf[i]-sft < 0)
		{
			++chg;
			sft -= 2;
		}
	}

	fout << chg << endl;

	fin.close();
	fout.close();

	return 0;
}