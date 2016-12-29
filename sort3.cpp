/*
ID: wgan8561
PROG: sort3
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
#define in2 "sort3.in"
#define out1 "data.out"
#define out2 "sort3.out"

#define MAX_N 1000

int N, L, A[4], V[MAX_N], ans;

int main()
{
	ifstream fin(in2);
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		fin >> V[i];
		++A[V[i]];
	}
	for (int i = 1; i <= 3; ++i)
	{
		A[i] += A[i-1];
		//cout << A[i] << endl;
	}
	fin.close();

	int i = A[0];
	int j = A[1];
	while (i < A[1] && j < A[2])
	{
		if (V[i] == 2 && V[j] == 1)
		{
			int tmp = V[i];
			V[i] = V[j];
			V[j] = tmp;
			++ans;
		}
		if (V[i] != 2)
			++i;
		if (V[j] != 1)
			++j;
	}

	i = 0;
	j = A[2];
	while (i < A[1] && j < A[3])
	{
		if (V[i] == 3 && V[j] == 1)
		{
			int tmp = V[i];
			V[i] = V[j];
			V[j] = tmp;
			++ans;
		}
		if (V[i] != 3)
			++i;
		if (V[j] != 1)
			++j;
	}

	i = A[1];
	j = A[2];
	while (i < A[2] && j < A[3])
	{
		if (V[i] == 3 && V[j] == 2)
		{
			int tmp = V[i];
			V[i] = V[j];
			V[j] = tmp;
			++ans;
		}
		if (V[i] != 3)
			++i;
		if (V[j] != 2)
			++j;
	}

	cout << ans << endl;

	for (int i = 0; i < N; ++i)
		if (i < A[V[i]-1] || i > A[V[i]])
			++L;
	ans += 2*L/3;
	
	ofstream fout(out2);
	fout << ans << endl;
	fout.close();

	return 0;
}