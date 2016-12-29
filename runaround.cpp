/*
ID: wgan8561
PROG: runround
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
#define in2 "runround.in"
#define out1 "data.out"
#define out2 "runround.out"

long long m, d, n[20]; //the number, digits, array representation of the number
long long v[10]; //if a certain digit was already visited

void inc() //increments array representation of number
{
	for (long long i = 0; i < d; ++i)
	{
		++n[i];
		if (n[i] == 10)
		{
			n[i] = 0;
			if (i == d-1)
				++d;
		}
		else
			break;
	}
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> m;
	int k = m;
	d = (long long)(log10(m))+1;

	for (long long i = d-1; i >= 0; --i)
	{
		long long p = (long long)(pow(10,i));
		n[i] = k/p;
		k = k-n[i]*p;
	}

	/*
	for (long long i = 0; i < d; ++i)
		cout << n[i];
	cout << endl;
	*/

	while (m < 1 << 30)
	{
		inc();
		++m;
		long long index = d-1;
		int c = 0;
		for (long long i = 0; i < d; ++i)
		{
			//cout << n[index] << " ";
			if (v[n[index]] == 1)
				break;
			++c;
			v[n[index]] = 1;
			long long step = n[index]%d;
			index = (index+(d-step))%d;
		}
		if (c == d && index == d-1)
			break;
		for (long long i = 0; i < 10; ++i)
			v[i] = 0;
		//cout << endl;
	}
	fout << m << endl;
	fin.close();
	fout.close();

	return 0;
}