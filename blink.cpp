//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=279
//2/16/15

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "blink.in"
#define out1 "data.out"
#define out2 "blink.out"

#define MAX_N 16
#define MAX_STATES (1 << (MAX_N))

int N;
long M;
pair<int,int> A[MAX_STATES];
int S = 0, S1 = 0, C = 1;


int main()
{
	ifstream fin(in2);
	fin >> N >> M;
	//cout << (1 << 31) << endl;
	//cout << "asdf" << endl;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		fin >> tmp;
		S = S | (tmp << (N-i-1));
	}
	A[S].first = C;
	++C;
	A[S].second = S;
	fin.close();
	//cout << "asdf" << endl;
	for (int i = 0; i < (1 << (N)); ++i )
	{
		if (i == M)
			break;
		S1 = S;
		S = S >> 1;
		if (S1 & 1)
			S = S | (1 << (N-1));
		S = S1 ^ S;
		//cout << S << endl;
		if (A[S].first != 0)
			break;
		A[S].first = C;
		++C;
		A[S].second = S;
	}
	int ans;
	if (C <= M)
	{
		//cout << M << " " << A[S].first << " " << C << endl;
		int B = (M+1-A[S].first)%(C-A[S].first);//+(C-A[S].first-1);
		//cout << C-A[S].first << endl;
		//cout << C << endl;
		//cout << B << endl;
		int D = C;
		C = A[S].first;
		//cout << C << endl;
		//cout << B << endl;
		int i;
		sort(A,(A+MAX_STATES));
		//for (int i = 0; i < MAX_STATES; ++i)
		//	cout << A[i].first << " " << A[i].second << endl;
		for (i = 0; i < MAX_STATES; ++i)
			if (A[i].first == C)
			{
				/*
				int z = i;
				for (int j = z; j < z+D-1; ++j)
				{
					cout << j << " " << A[j].second << endl;
					for (int k = 0; k < N; ++k)
					{
						if (A[j].second & (1 << (N-1-k)))
							cout << 1;
						else
							cout << 0;
					}
					cout << endl;
				}
				*/
				break;
			}
		ans = A[i+B].second;
		//cout << i+B << endl;
		//cout << A[i+B].first;
		//cout << ans << endl;
		//cout << ans << endl;
	}
	else
	{
		ans = S;
	}
	
	ofstream fout(out2);
	for (int i = 0; i < N; ++i)
	{
		if (ans & (1 << (N-i-1)))
			fout << 1 << endl;
		else
			fout << 0 << endl;
	}
	fout.close();

	return 0;
}