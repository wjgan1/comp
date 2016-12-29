/*
ID: wgan8561
PROG: agrinet
LANG: C++
*/

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
#define in2 "agrinet.in"
#define out1 "data.out"
#define out2 "agrinet.out"

int n, gr[100][100];
int dist[100];
bool intree[100];
int ans;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> gr[i][j];
		
	for (int i = 1; i < n; ++i)
	{
		dist[i] = 1 << 30;
		intree[i] = false;
	}

	int curr = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += dist[curr];
		intree[curr] = true;
		for (int j = 0; j < n; ++j)
			if (j != curr && gr[curr][j] < dist[j])
				dist[j] = gr[curr][j];
		curr = -1;
		for (int j = 0; j < n; ++j)
			if (!intree[j] && (curr == -1 || dist[j] < dist[curr]))
				curr = j;
	}

	fout << ans << endl;

	fin.close();
	fout.close();

	return 0;
}