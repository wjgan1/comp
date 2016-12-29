//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define in1 "_data.in"
#define in2 "wifi.in"
#define out1 "_data.out"
#define out2 "wifi.out"

int N, A, B;
int pos[2000];
double best[2000];

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	fin >> N >> A >> B;
	for (int i = 0; i < N; ++i)
		fin >> pos[i];
	sort(pos,pos+N);

	//for (int i = 0; i < N; ++i)
	//	best[i] = 1 << 30;

	best[0] = A;
	for (int i = 1; i < N; ++i)
	{
		best[i] = 1.0*(pos[i]-pos[0])/2*B+A;
		for (int j = i-1; j >= 0; --j)
			if (best[j]+1.0*(pos[i]-pos[j+1])/2.0*B+A < best[i])
				best[i] = best[j]+1.0*(pos[i]-pos[j+1])/2.0*B+A;
		//cout << i << " " << best[i] << endl;
	}
	/*
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N-k; ++i)
		{
			int j = i+k;
			mincost[i][j] = 1.0*(pos[j]-pos[i])/2.0*B+A;
			for (int l = i; l < j; ++l)
				mincost[i][j] = min(mincost[i][j],mincost[i][l]+mincost[l+1][j]);
		}
	}
	*/
	fout << fixed;
	printf("%.3f\n",best[N-1]);
	fout << best[N-1] << endl;
	fin.close();
	fout.close();

	return 0;
}