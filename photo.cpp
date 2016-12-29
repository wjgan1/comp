//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=280
//date

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "photo.in"
#define out1 "data.out"
#define out2 "photo.out"

int N, K, C, ANS = 1;
vector<pair<int,int> > V;

int main()
{
	ifstream fin(in2);
	fin >> N >> K;
	V.resize(2*K);
	for (int i = 0; i < V.size(); i += 2)
	{
		int A, B;
		fin >> A >> B;
		V[i].first = V[i+1].second = A;
		V[i].second = V[i+1].first = B;
	}
	fin.close();

	sort(V.begin(),V.end());

	for (int i = 0; i < V.size(); ++i)
	{
		if (V[i].first > V[i].second && V[i].second > C)
		{
			C = V[i].first;
			++ANS;
		}
	}
	
	ofstream fout(out2);
	fout << ANS << endl;
	fout.close();

	return 0;
}