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
#define in2 "islands.in"
#define out1 "data.out"
#define out2 "islands.out"

#define MAX_N 100000

int N, ANS, A[MAX_N];
vector<pair<int,int> > V;

int main()
{
	ifstream fin(in1);
	fin >> N;
	int lo;
	for (int i = 0; i < N; ++i)
	{
		fin >> A[i];
		if (A[i] < lo)
			lo = A[i];
	}
	fin.close();

	if (A[0] >= A[1])
	{
		V.push_back(make_pair(A[1]-lo,1));
		V.push_back(make_pair(A[0]-lo,-1));
	}
	for (int i = 1; i < N; ++i)
	{
		if (A[i] > A[i-1])
		{
			V.push_back(make_pair(A[i-1]-lo,1));
			V.push_back(make_pair(A[i]-lo,-1));
		}
	}
	sort(V.begin(),V.end());

	//for (int i = 0; i < V.size(); ++i)
	//	cout << V[i].first << " " << V[i].second << endl;

	int SUM = 0;
	for (int i = 0; i < V.size(); ++i)
	{
		SUM += V[i].second;
		if (SUM > ANS)
			ANS = SUM;
	}
	
	ofstream fout(out1);
	fout << ANS << endl;
	fout.close();

	return 0;
}