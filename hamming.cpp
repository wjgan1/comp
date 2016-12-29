/*
ID: wgan8561
PROG: hamming
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
#define in2 "hamming.in"
#define out1 "data.out"
#define out2 "hamming.out"

#define MAX_N 64

int N, B, D, S, A[MAX_N];

int main()
{
	ifstream fin(in2);
	fin >> N >> B >> D;
	fin.close();

	A[0] = 0;
	S = 1;
	for (int i = 1; S < N && i < (int)pow(2,B); ++i)
	{
		bool works = true;
		for (int j = 0; j < S; ++j)
		{
			int tmp = A[j] ^ i;
			//cout << tmp << endl;
			int count = 0;
			for (int i = 0; i < B; ++i)
				if ((1 << i) & tmp)
					++count;
			if (count < D)
			{
				works = false;
				break;
			}
		}
		if (works == true)
		{
			//cout << "no" << endl;
			A[S] = i;
			++S;
		}
	}	
	
	ofstream fout(out2);
	fout << A[0];
	for (int i = 1; i < S; ++i)
	{
		if (i%10 == 0)
			fout << "\n" << A[i];
		else
			fout <<	" " << A[i];
	}
	fout << endl;
	fout.close();

	return 0;
}