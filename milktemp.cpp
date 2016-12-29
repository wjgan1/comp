//foreverbronze
//http://usaco.org/index.php?page=viewproblem2&cpid=341
//2/10/2015

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "milktemp.in"
#define out1 "data.out"
#define out2 "milktemp.out"

#define MAXN 20000

int N, X, Y, Z;
vector< pair<int,int> > t;

int main()
{
	int start = -1;
	int finish = 1;

	ifstream fin(in2);
	ofstream fout(out2);

	fin >> N >> X >> Y >> Z;
	t.resize(2*N);

	for(int i = 0; i < 2*N; i+=2)
	{
		int A, B;
		fin >> A >> B;
		t[i].first = A;
		t[i].second = start;
		t[i+1].first = B;
		t[i+1].second = finish;
	}

	sort(t.begin(),t.end());

	//for (int i = 0; i < 2*N; ++i)
	//	cout << t[i].first << " " << t[i].second << endl;

	int sum = N*X;
	int max = sum;
	for (int i = 0; i < 2*N; ++i)
	{
		if (t[i].second == start)
		{
			sum -= X;
			sum += Y;
		}
		else if (t[i].second == finish)
		{
			sum -= Y;
			sum += Z;
		}
		if (sum > max)
		{
			max = sum;
		}
	}

	fout << max << endl;

	fin.close();
	fout.close();

	return 0;
}