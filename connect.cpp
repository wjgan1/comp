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
#define in2 "connect.in"
#define out1 "data.out"
#define out2 "connect.out"

#define M_N 10 //max cows

int N, V[M_N], X[M_N], Y[M_N]; //cows, visisted, x coord, y coord
int ANS = 0;

void solve(int v, int n, int d)
{
	if (v == N-1)
	{
		if (X[n] == 0 || Y[n] == 0)
			++ANS;
		return;
	}
	if (V[n] == 1)
	V[n] = 1;
	for (int i = 0; i < N; ++i)
		if (i != n && (X[n] == X[i] || Y[n] == Y[i]))
			solve(v+1,i);
	V[n] = 0;
}

int main()
{
	ifstream fin(in1);
	fin >> N;
	for (int i = 0; i < N; ++i)
		fin >> X[i] >> Y[i];
	fin.close();

	for (int i = 0; i < N; ++i)
		if (X[i] == 0 || Y[i] == 0)
			solve(0,i);
	
	ofstream fout(out1);
	fout << ANS << endl;
	fout.close();

	return 0;
}