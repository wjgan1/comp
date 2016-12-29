/*
ID: wgan8561
PROG: nocows
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
#define in2 "nocows.in"
#define out1 "data.out"
#define out2 "nocows.out"

#define mod 9901

int n, k;
int mt[201][101];
int pw[201];

int solve(int a, int b)
{
	//cout << a << " " << b << endl;
	if (b == 0 && a > 0)
	{
		mt[a][b] = 0;
		return 0;
	}
	if (mt[a][b] != -1)
		return mt[a][b];
	if (a%2== 0)
	{
		mt[a][b] = 0;
		return 0;
	}
	
	if (a-1 < 2*(b-1))
	{
		mt[a][b] = 0;
		return 0;
	}
	int tot = 0;
	tot = (tot+2*solve(a-2,b-1)%mod)%mod;
	int c = a-3;
	//cout << a << " " << b << endl;
	for (int i = 2; i <= c/2; i += 2)
	{
		int sub = 0;
		int sub2 = 0;
		for (int j = 2; j <= b-1; ++j)
		{
		 	sub = (sub+solve(i+1,j)%mod*solve(c-i+1,b-1)%mod%mod)%mod;
		 	//if (sub-sub2 == 3740)
		 	//	cout << a << " " << b << " " << i+1 << " " << j << " " << c-i+1 << " " << b-1 << endl;
		 	sub2 = sub;
		}
		for (int j = 2; j <= b-2; ++j)
		{
			sub = (sub+solve(i+1,b-1)%mod*solve(c-i+1,j)%mod%mod)%mod;
			//if (sub-sub2 == 3740)
		 	//	cout << a << " " << b << " " << i+1 << " " << j << " " << c-i+1 << " " << b-1 << endl;
		 	sub2 = sub;
		}
		if (c-i != i)
			sub = 2*sub%mod;
		tot = (tot+sub)%mod;
	}
	//cout << tot << endl;
	mt[a][b] = tot;
	//cout << "tot is " << tot << endl;
	return tot;

}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < 101; ++j)
			mt[i][j] = -1;

	pw[1] = 1;
	for (int i = 2; i < 201; ++i)
		pw[i] = 2*pw[i-1]%mod;

	fin >> n >> k;
	//mt[0][0] = 1;
	mt[1][1] = 1;
	mt[3][2] = 1;

	fout << solve(n,k) << endl;
	/*
	cout << "     ";
	for (int i = 0; i <= n; ++i)
		printf("%5d", i);
	cout << endl;
	for (int j = 0; j <= k; ++j)
	{
		printf("%5d",j);
		for (int i = 0; i <= n; ++i)
			printf("%5d", mt[i][j]);
		cout << endl;
	}
	*/
	//cout << solve(n-2,k-1) << endl;
	fin.close();
	fout.close();

	return 0;
}