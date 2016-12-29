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
#define in2 "3lines.in"
#define out1 "data.out"
#define out2 "3lines.out"

#define MAX_N 50000

int N, C[MAX_N];
pair<int,int> X[MAX_N], Y[MAX_N], NX[MAX_N], NY[MAX_N];

int main()
{
	ifstream fin(in1);
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		fin >> X[i].first >> Y[i].first;
		X[i].second = Y[i].second = i;
	}
	fin.close();

	for (int i = 0; i < 3; ++i)
	{
		sort(X,X+N);
		sort(Y,Y+N);
		
		//for (int i = 0; i < N; ++i)
		//{
		//	cout << X[i].first << " " << Y[i].first << endl;
		//}
		//cout << endl;
		
		int s_index = 0; //start index
		int c_count = 1; //current count
		pair<int,int> xm = make_pair(0,-1); //x max;
		for (int j = 0; j < N-1; ++j)
		{
			if (X[j].first == X[j+1].first)
				++c_count;
			else
			{
				if (c_count > xm.first && s_index != 0)
				{
					xm.first = c_count;
					xm.second = s_index;
				}
				c_count = 1;
				s_index = j+1;
			}
		}
		if (c_count > xm.first && s_index != 0)
		{
			xm.first = c_count;
			xm.second = s_index;
		}

		s_index = 0;
		c_count = 1;
		pair<int,int> ym = make_pair(0,-1);
		for (int j = 0; j < N-1; ++j)
		{
			if (Y[j].first == Y[j+1].first)
				++c_count;
			else
			{
				if (c_count > ym.first && s_index != 0)
				{
					ym.first = c_count;
					ym.second = s_index;
				}
				c_count = 1;
				s_index = j+1;
			}
		}
		if (c_count > ym.first && s_index != 0)
		{
			ym.first = c_count;
			ym.second = s_index;
		}

		//cout << xm.first << " " << ym.first << endl << endl;

		if (xm.first > ym.first)
			for (int i = xm.second; i < xm.second+xm.first; ++i)
				C[X[i].second] = 1;
		else
			for (int i = ym.second; i < ym.second+ym.first; ++i)
				C[Y[i].second] = 1;
		
		for (int i = 0; i < N; ++i)
		{
			if (C[X[i].second] == 1)
				X[i] = make_pair(-1,-1);
			if (C[Y[i].second] == 1)
				Y[i] = make_pair(-1,-1);
		}
	}
	
	ofstream fout(out1);
	for (int i = 0; i < N; ++i)
	{
		//cout << C[i] << endl;
		if (C[i] == 0)
		{
			fout << 0 << endl;
			fout.close();
			return 0;
		}
	}
	fout << 1 << endl;
	fout.close();

	return 0;
}