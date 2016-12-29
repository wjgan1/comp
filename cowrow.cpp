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
#define in2 "cowrow.in"
#define out1 "data.out"
#define out2 "cowrow.out"

#define MAX_N 1000

int N, ANS, C[MAX_N];

int main()
{
	ifstream fin(in1);
	fin >> N;
	for (int i = 0; i < N; ++i)
		fin >> C[i];
	fin.close();

	for (int i = 0; i < N; ++i)
	{
		int W = C[i]; //wild card
		int CR = 1; //current row
		int B = C[0]; //breed behind current cow
		for (int j = 1; j < N; ++j)
		{
			if (C[j] == B)
				++CR;
			else if (C[j] != W)
			{
				if (CR > ANS)
					ANS = CR;
				B = C[j];
				CR = 1;
			}
		}
		if (CR > ANS)
			ANS = CR;
	}
	
	ofstream fout(out1);
	fout << ANS << endl;
	fout.close();

	return 0;
}