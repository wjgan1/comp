//foreverbronze
//http://usaco.org/index.php?page=open12problems
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define in1 "data.in"
#define in2 "unlock.in"
#define out1 "data.out"
#define out2 "unlock.out"

int n[3];
int a[3][100][2];
int o[20][20][20][20];

void dfs(int z)
{
	for (int i = 0;)
	if (R == 1)
		return;
	if (abs(X[N[z]]) > M_A-S || abs(Y[N[z]]) > M_A-S)
	{
		NR[z] = R = 1;
		return;
	}
	if (A[X[N[z]]+S][Y[N[z]]+S] == 1)
		return;
	A[X[N[z]]+S][Y[N[z]]+S] = 1;

	for (int i = (z+1)%P; i != z; i = (i+1)%P)
		if (NR[i] == 0)
			for (int j = N[z]; j < N[z+1]; ++j)
				for (int k = N[i]; k < N[i+1]; ++k)
					if (X[j] == X[k] && Y[j] == Y[k])
						return;

	for (int i = N[z]; i < N[z+1] && R == 0; ++i)
	{
		++X[i];
	}
	dfs(z);
	for (int i = N[z]; i < N[z+1] && R == 0; ++i)
	{
		X[i] -= 2;
	}
	dfs(z);
	for (int i = N[z]; i < N[z+1] && R == 0; ++i)
	{
		--X[i];
		++Y[i];
	}
	dfs(z);
	for (int i = N[z]; i < N[z+1] && R == 0; ++i)
	{
		Y[i]-= 2;
	}
	dfs(z);
	for (int i = N[z]; i < N[z+1] && R == 0; ++i)
	{
		++Y[i];
	}

}

int main()
{
	ifstream fin(in1);
	fin >> n[0] >> n[1] >> n[2];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n[i]; ++j)
			fin >> a[i][j][0] >> a[i][j][1];
	fin.close();

	solve();

	for (int i = 0; i < P*P; ++i)
	{	
		for (int j = 0; j < M_A; ++j)
			for (int k = 0; k < M_A; ++k)
				A[j][k] = 0;
		R = 0;
		if (NR[i%P] == 0)
			dfs(i%P);
	}

	for (int i = 0; i < P; ++i)
		cout << NR[i] << endl;
	
	ofstream fout(out1);
	for (int i = 0; i < P; ++i)
	{
		if (NR[i] == 0)
		{
			fout << "0" << endl;
			fout.close();
			return 0;
		}
	}
	fout << "1" << endl;
	fout.close();

	return 0;
}