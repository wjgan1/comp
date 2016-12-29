/*
ID: wgan8561
PROG: subset
LANG: C++
*/

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
#define in2 "subset.in"
#define out1 "data.out"
#define out2 "subset.out"

long long n, np; //n prime
long long ps[40]; //partial sums of 1+2+3+...+n
long long s[40*41/4][40]; //number of ways a number can be added up to using the first n numbers

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> n;
	np = n*(n+1)/4;
	for (long long i = 1; i <= n; ++i)
		ps[i] = i*(i+1)/2;

	//if (ps[n]%2 == 1)
	//{
	//	fout << 0 << endl;
	//	return 0;
	//}

	s[0][0] = 1;
	for (long long i = 0; i <= np; ++i)
	{
		for (long long j = 0; j <= n; ++j)
		{
			s[i][j] += s[i][j-1];
			//if (j == i)
			//	s[i][j] += 1;
			if (i-j >= 0)
				s[i][j] += s[i-j][j-1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << s[j][i] << " ";
		cout << endl;
	}
	fout << s[np][n]/2 << endl;
	
	fin.close();
	fout.close();

	return 0;
}