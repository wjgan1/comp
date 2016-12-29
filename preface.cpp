/*
ID: wgan8561
PROG: preface
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
#define in2 "preface.in"
#define out1 "data.out"
#define out2 "preface.out"

int n, t_rnc[9], rnc[9];
int r_n[] = {10000, 5000, 1000,500,100,50,10,5,1};
char c_rn[] = {'A','D','M','D','C','L','X','V','I'};

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int m = i;
		//cout << m << " ";
		for (int j = 2; j <= 8; ++j)
		{
		//	cout << m << " ";
			while (m >= r_n[j])
			{
				m -= r_n[j];
				++rnc[j];
			}
			if (rnc[j] > 3 && rnc[j-1]*r_n[j-1]+rnc[j]*r_n[j] == r_n[j-2]-r_n[j])
			{
				rnc[j] -= 3;
				rnc[j-1] -= 1;
				rnc[j-2] += 1;
			}
			else if (rnc[j] > 3 && rnc[j]*r_n[j] == r_n[j-1]-r_n[j])
			{
				rnc[j] -= 3;
				rnc[j-1] += 1;
			}
		}
		for (int j = 2; j <= 8; ++j)
		{
			//cout << rnc[j] << " ";
			t_rnc[j] += rnc[j];
			rnc[j] = 0;
		}
		//cout << endl;
	}

	for (int i = 8; i > 1; --i)
		if (t_rnc[i] > 0)
			fout << c_rn[i] << " " << t_rnc[i] << endl;

	fin.close();
	fout.close();

	return 0;
}