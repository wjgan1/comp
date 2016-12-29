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
#define in2 "mroute.in"
#define out1 "_data.out"
#define out2 "mroute.out"

int n, m, x;
int ladj[500][500], cadj[500][500];
double dist[500];
int lat[500], cap[500];
bool vis[500];

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n >> m >> x;
	for (int i = 0; i < m; ++i)
	{
		int v1, v2, lt, cp;
		fin >> v1 >> v2 >> lt >> cp;
		ladj[v1-1][v2-1] = ladj[v2-1][v1-1] = lt;
		cadj[v1-1][v2-1] = cadj[v2-1][v1-1] = cp;
	}

	for (int i = 0; i < n; ++i)
	{
		dist[i] = 1 << 30;
		vis[i] = false;
	}

	int ci = 0;
	dist[0] = 0;
	lat[0] = 0;
	cap[0] = 1 << 30;
	for (int i = 0; i < n; ++i)
	{
		//cout << ci << " " << dist[ci] << endl;
		vis[ci] = true;
		for (int i = 0; i < n; ++i)
		{
			if (ladj[ci][i] != 0)
			{
				int lt = ladj[ci][i]+lat[ci];
				int cp = min(cadj[ci][i],cap[ci]);
				//cout << 1.0*lt+1.0*x/cp << endl;
				if (1.0*lt+1.0*x/cp < dist[i])
				{
					dist[i] = 1.0*lt+1.0*x/cp;
					lat[i] = lt;
					cap[i] = cp;
				}
			}
		}
		ci = -1;
		for (int i = 0; i < n; ++i)
			if (!vis[i] && (ci == -1 || dist[i] < dist[ci]))
				ci = i;
	}

	fout << (int)dist[n-1] << endl;
	fin.close();
	fout.close();

	return 0;
}