/*
ID: wgan8561
PROG: comehome
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
#define in2 "comehome.in"
#define out1 "data.out"
#define out2 "comehome.out"

int e, loc[52], adj[52][52];
int vis[52], dist[52];


int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	fin >> e;
	//cout << e << endl;
	for (int i = 0; i < e; ++i)
	{
		char a, b;
		int d;
		fin >> a >> b >> d;
		//cout << (int)a << " " << (int)b << " " << d << endl;
		if (a-'a' >= 0)
			a = a-'a'+'A'+26;
		if (b-'a' >= 0)
			b = b-'a'+'A'+26;
		//cout << (int)a << " " << (int)b << " " << d << endl;
		if (adj[a-'A'][b-'A'] == 0 || d < adj[a-'A'][b-'A'])
		{
			adj[a-'A'][b-'A'] = d;
			adj[b-'A'][a-'A'] = d;
		}
	}
	/*
	for (int i = 0; i < 52; ++i)
	{
		for (int j = 0; j < 52; ++j)
			cout << adj[j][i] << " ";
		cout << endl;
	}
	*/
	for (int i = 0; i < 52; ++i)
		dist[i] = 1 << 30;

	int c = 25;
	dist[25] = 0;
	while (c != -1)
	{
		vis[c] = 1;
		if (c < 25)
		{
			fout << (char)(c+'A') << " " << dist[c] << endl;
			fin.close();
			fout.close();
			return 0;
		}
		for (int i = 0; i < 52; ++i)
			if (adj[c][i] != 0 && dist[c]+adj[c][i] < dist[i])
				dist[i] = dist[c]+adj[c][i];
		int min = 1 << 30;
		c = -1;
		for (int i = 0; i < 52; ++i)
			if (vis[i] == 0 && dist[i] < min)
			{
				min = dist[i];
				c = i;
			}
	}

	fin.close();
	fout.close();

	return 0;
}