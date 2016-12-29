//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=281
//2/16/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "haywire.in"
#define out1 "data.out"
#define out2 "haywire.out"

#define MAX_N 12

int N, ANS = 1 << 30, CVAL, E[MAX_N][MAX_N], V[MAX_N], S[MAX_N];

void dfs(int D)
{
	if (D == N)
	{
		ANS = CVAL < ANS ? CVAL : ANS;
		//for (int i = 0; i < N; ++i)
		//	cout << S[i] << " ";
		//cout << endl;
		return;	
	}
	for (int i = 0; i < N; ++i)
	{
		if (V[i] == 0)
		{
			V[i] = 1;
			S[D] = i;
			int tmp = CVAL;
			for (int j = 0; j < D; ++j)
				if (E[S[j]][i] == 1)
					CVAL += D-j;
			if (CVAL > ANS)
			{
				V[i] = 0;
				CVAL = tmp;
				return;
			}
			dfs(D+1);
			V[i] = 0;
			CVAL = tmp;
		}
	}
}

int main()
{
	ifstream fin(in2);
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		int A, B, C;
		fin >> A >> B >> C;
		E[i][A-1] = E[i][B-1] = E[i][C-1] = 1;
	}
	fin.close();

	dfs(0);
	
	ofstream fout(out2);
	fout << ANS << endl;
	fout.close();

	return 0;
}