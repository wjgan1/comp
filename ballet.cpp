//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=278
//2/15/15

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "ballet.in"
#define out1 "data.out"
#define out2 "ballet.out"

#define fl 0
#define fr 1
#define rl 2
#define rr 3
#define N 0
#define E 1
#define S 2
#define W 3

int Z, XM, Xm, YM, Ym, d, FX[4], FY[4];
int ANS;

void check()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i+1; j < 4; ++j)
		{
			if (FX[i] == FX[j] && FY[i] == FY[j])
			{
				//cout << i << " " << j << " " << FX[i] << " " << FY[i] << " " << FX[j] << " " << FY[j] << endl;
				ANS = -1;
				return;
			}
		}
		if (FX[i] > XM)
			XM = FX[i];
		else if (FX[i] < Xm)
			Xm = FX[i];
		if (FY[i] > YM)
			YM = FY[i];
		else if (FY[i] < Ym)
			Ym = FY[i];
	}
}

void front(int m)
{
	if (d == N)
		++FY[m];
	else if (d == E)
		++FX[m];
	else if (d == S)
		--FY[m];
	else
		--FX[m];
	check();
}

void back(int m)
{
	if (d == N)
		--FY[m];
	else if (d == E)
		--FX[m];
	else if (d == S)
		++FY[m];
	else
		++FX[m];
	check();
}

void left(int m)
{
	if (d == N)
		--FX[m];
	else if (d == E)
		++FY[m];
	else if (d == S)
		++FX[m];
	else
		--FY[m];
	check();
}

void right(int m)
{
	if (d == N)
		++FX[m];
	else if (d == E)
		--FY[m];
	else if (d == S)
		--FX[m];
	else
		++FY[m];
	check();
}

void pivot(int m)
{
	d = (d+1)%4;
	for (int i = 0; i < 4; ++i)
	{
		int A = FX[i];
		int B = FY[i];
		FX[i] = B-FY[m]+FX[m];
		FY[i] = FX[m]-A+FY[m];
		//cout << FX[i] << " " << FY[i] << endl;
	}
	check();
}

int main()
{
	ifstream fin(in2);
	fin >> Z;
	
	FX[fl] = 0;
	FY[fl] = 1;
	FX[fr] = 1;
	FY[fr] = 1;
	FX[rl] = 0;
	FY[rl] = 0;
	FX[rr] = 1;
	FY[rr] = 0;

	XM = 1;
	Xm = 0;
	YM = 1;
	Ym = 0;
	d = 0;

	string str;
	string a;
	string b;
	for (int i = 0; i < Z && ANS != -1; ++i)
	{
		fin >> str;
		if (str.compare("FLF") == 0)
			front(fl);
		else if (str.compare("FLB") == 0)
			back(fl);
		else if (str.compare("FLP") == 0)
			pivot(fl);
		else if (str.compare("FLL") == 0)
			left(fl);
		else if (str.compare("FLR") == 0)
			right(fl);
		else if (str.compare("FRF") == 0)
			front(fr);
		else if (str.compare("FRB") == 0)
			back(fr);
		else if (str.compare("FRP") == 0)
			pivot(fr);
		else if (str.compare("FRL") == 0)
			left(fr);
		else if (str.compare("FRR") == 0)
			right(fr);
		else if (str.compare("RLF") == 0)
			front(rl);
		else if (str.compare("RLB") == 0)
			back(rl);
		else if (str.compare("RLP") == 0)
			pivot(rl);
		else if (str.compare("RLL") == 0)
			left(rl);
		else if (str.compare("RLR") == 0)
			right(rl);
		else if (str.compare("RRF") == 0)
			front(rr);
		else if (str.compare("RRB") == 0)
			back(rr);
		else if (str.compare("RRP") == 0)
			pivot(rr);
		else if (str.compare("RRL") == 0)
			left(rr);
		else if (str.compare("RRR") == 0)
			right(rr);
	}
	
	ofstream fout(out2);
	if (ANS != -1)
		ANS = (XM-Xm+1)*(YM-Ym+1);
	cout << XM << " " << Xm << " " << YM << " " << Ym << endl;
	fout << ANS << endl;
	fout.close();

	return 0;
}