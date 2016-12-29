//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=377
//2/13/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "slowdown.in"
#define out1 "data.out"
#define out2 "slowdown.out"

int N;
vector<int> T, D;

int main()
{
	ifstream fin(in2);
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		char c;
		int v;
		fin >> c >> v;
		if (c == 'T')
			T.push_back(v);
		else
			D.push_back(v);

	}
	fin.close();

	sort(T.begin(),T.end());
	sort(D.begin(),D.end());

	int i = 0;
	int j = 0;
	double t = 0;
	double s = 1;
	double d = 0;
	while ((i < T.size() || j < D.size()) && d < 1000)
	{
		if (j >= D.size() || (i < T.size() && T[i]-t < (D[j]-d)*s))
		{
			d = d+(T[i]-t)/s;
			t = T[i];
			++s;
			++i;
		}
		else
		{
			t = t+(D[j]-d)*s;
			d = D[j];
			++s;
			++j;
		}
	}

	double ans = (1000-d)*s+t;
	int integer_ans;
	if (ans - (int)ans >= 0.5)
		integer_ans = (int)ans+1;
	else
		integer_ans = (int)ans;
	
	ofstream fout(out2);
	fout << integer_ans << endl;
	fout.close();

	return 0;
}