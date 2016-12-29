//foreverbronze

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define in1 "data.in"
#define in2 "meeting.in"
#define out1 "data.out"
#define out2 "meeting.out"

int n, e;
int badj[100][100], eadj[100][100];
bool breach[100][10001];
bool ereach[100][10001];
int mn;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> e;
	for (int i = 0; i < e; ++i)
	{
		int a, b, c, d;
		fin >> a >> b >> c >> d;
		badj[a-1][b-1] = c;
		eadj[a-1][b-1] = d;
	}

	breach[0][0] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 100*n+1; ++j)
			if (breach[i][j])
				for (int k = i+1; k < n; ++k)
					if (badj[i][k] != 0)
						breach[k][j+badj[i][k]] = true;
	ereach[0][0] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 100*n+1; ++j)
			if (ereach[i][j])
				for (int k = i+1; k < n; ++k)
					if (eadj[i][k] != 0)
						ereach[k][j+eadj[i][k]] = true;

	mn = 1 << 30;
	for (int i = 0; i < 100*n+1; ++i)
		if (mn == 1 << 30 && breach[n-1][i] && ereach[n-1][i])
			mn = i;
	if (mn == 1 << 30)
		fout << "IMPOSSIBLE" << endl;
	else
		fout << mn << endl;

	fin.close();
	fout.close();

	return 0;
}