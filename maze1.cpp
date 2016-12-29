/*
ID: wgan8561
PROG: maze1
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
#define in2 "maze1.in"
#define out1 "data.out"
#define out2 "maze1.out"

#define _i 2*i+1
#define _j 2*j+1

int w, h;
char gr[2*38+1][2*100+1];
int n, vis[38][100], dist[38][100];
int fd[38][100];
int ex[2], ey[2];
int ans;

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> w >> h;
	string s;
	getline(fin,s);
	int index = 0;
	for (int i = 0; i < 2*h+1; ++i)
	{
		getline(fin,s);
		for (int j = 0; j < 2*w+1; ++j)
		{
			gr[j][i] = s[j];
			if ((i == 0 || i == 2*h || j == 0 || j == 2*w) && gr[j][i] == ' ')
			{
				ex[index] = (j-1)/2;
				ey[index] = (i-1)/2;
				//cout << ex[index] << " " << ey[index] << endl;
				++index;
			}
		}
	}
	/*
	for (int i = 0; i < 2*h+1; ++i)
	{
		for (int j = 0; j < 2*w+1; ++j)
			cout << gr[j][i];
		cout << endl;
	}
	*/
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			for (int k = 0; k < h; ++k)
			{
				if (j == ex[i] && k == ey[i])
					dist[j][k] = 1;
				else
					dist[j][k] = 1 << 30;
				vis[j][k] = 0;
			}
		}
		int cx = ex[i];
		int cy = ey[i];
		for (int j = 0; j < w*h; ++j)
		{
			//cout << cx << " " << cy << endl;
			vis[cx][cy] = 1;
			if (fd[cx][cy] == 0)
				fd[cx][cy] = dist[cx][cy];
			else if (dist[cx][cy] < fd[cx][cy] && dist[cx][cy] > ans)
				ans = dist[cx][cy];
			else if (dist[cx][cy] >= fd[cx][cy] && fd[cx][cy] > ans)
			{
				ans = fd[cx][cy];
				//cout << ans << endl;
			}
			if (cx > 0 && gr[2*cx][2*cy+1] == ' ' && dist[cx][cy]+1 < dist[cx-1][cy])
				dist[cx-1][cy] = dist[cx][cy]+1;
			if (cx < w-1 && gr[2*cx+2][2*cy+1] == ' ' && dist[cx][cy]+1 < dist[cx+1][cy])
				dist[cx+1][cy] = dist[cx][cy]+1;
			if (cy > 0 && gr[2*cx+1][2*cy] == ' ' && dist[cx][cy]+1 < dist[cx][cy-1])
				dist[cx][cy-1] = dist[cx][cy]+1;
			if (cy < h-1 && gr[2*cx+1][2*cy+2] == ' ' && dist[cx][cy]+1 < dist[cx][cy+1])
				dist[cx][cy+1] = dist[cx][cy]+1;
			int min = 1 << 30;
			for (int k = 0; k < w; ++k)
				for (int l = 0; l < h; ++l)
					if (vis[k][l] == 0 && dist[k][l] < min)
					{
						cx = k;
						cy = l;
						min = dist[k][l];
					}
		}
		/*
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
				cout << dist[j][i] << "\t";
			cout << endl;
		}
		cout << endl;
		*/
	}

	fout << ans << endl;
	fin.close();
	fout.close();

	return 0;
}