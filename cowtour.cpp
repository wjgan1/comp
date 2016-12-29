/*
ID: wgan8561
PROG: cowtour
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
#include <cstdio>
#include <string>

using namespace std;

#define in1 "data.in"
#define in2 "cowtour.in"
#define out1 "data.out"
#define out2 "cowtour.out"

int n, x[150], y[150];
double adj[150][150];
double longest[150];
double longest2[150];
double ans = 1 << 29;

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(1.0*(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> n;
	for (int i = 0; i < n; ++i)
		fin >> x[i] >> y[i];

	for (int i = 0; i < n; ++i)
	{
		string s;
		fin >> s;
		for (int j = 0; j < n; ++j)
		{
			if (s[j] == '0')
				adj[j][i] = 1 << 29;
			else
			{
				double d = dist(x[j],y[j],x[i],y[i]);
				adj[j][i] = adj[i][j] = d;
			}
			if (i == j)
				adj[i][j] = 0;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (adj[i][k]+adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k]+adj[k][j];
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%.3f ",adj[j][i]);
		cout << endl;
	}
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (adj[i][j] != 1 << 29 && adj[i][j] > longest[i])
				longest[i] = adj[i][j];
			if (adj[i][j] != 1 << 29 && longest2[j] > longest2[i])
				longest2[i] = longest2[j];
			else if (longest[i] > longest2[i])
				longest2[i] = longest[i];
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (adj[i][j] != 1 << 29 && longest2[j] > longest2[i])
				longest2[i] = longest2[j];
	/*
	for (int i = 0; i < n; ++i)
		cout << longest2[i] << endl;
	*/
	/*
	for (int i = 0; i < n; ++i)
		cout << longest[i] << " ";
	cout << endl;
	*/
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (adj[i][j] == 1 << 29)
			{
				double d = dist(x[i],y[i],x[j],y[j]);
				//cout << longest[i]+longest[j]+d << endl;
				//cout << longest2[i] << " " << longest[i]+longest[j]+d << " ";
				double tmp = max(max(longest2[i],longest[i]+longest[j]+d),longest2[j]);
				//cout << tmp << endl;
				if (tmp < ans)
				{
					//cout << i << " " << longest[i] << " " << d << " " << j << " " << longest[j] << endl;
					ans = tmp;
				}
			}

	FILE *f = fopen(out2,"w");
	fprintf(f,"%.6f\n",ans);

	fin.close();
	fout.close();

	return 0;
}