/*
ID: wgan8561
PROG: fracdec
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
#define in2 "fracdec.in"
#define out1 "data.out"
#define out2 "fracdec.out"

#define M 1000000007
#define P 10007
#define S 107

int v[500000], h[500000], p[500000];
int n, d, dc = -1, ed = -1;

int hxsh(int prv, int nxt)
{
	long long l = 1LL*prv*P%M;
	return (int)((l+nxt+S)%M);
}

int chash(int beg, int end)
{
	long long l = (1LL*h[beg-1]*p[end-beg+1])%M;
	return (int)((M+h[end]-l)%M);
}

bool check(int hsh, int beg, int len)
{
	for (int i = 0; i < 6; ++i)
	{
		int x = chash(beg,beg+len-1);
		if (x != hsh)
			return false;
		else
			beg = beg-len;
	}
	return true;
}

int main()
{
	ifstream fin(in2);
	ofstream fout(out2);

	p[0] = 1;
	for (int i = 1; i < 500000; ++i)
		p[i] = (int)((1LL*p[i-1]*P)%M);

	fin >> n >> d;
	for (int i = 0; i < 500000; ++i)
	{
		if (n == 0)
		{
			ed = i;
			break;
		}
		if (n < d && dc == -1 && i == 0)
			dc = 1;
		else if (n < d && dc == -1)
			dc = i;
		if (i != 0 && n < d)
			n = n*10;
		v[i] = n/d;
		n = n-v[i]*d;
		if (i == 0)
			h[i] = hxsh(0,v[i]);
		else
			h[i] = hxsh(h[i-1],v[i]);
	}
	/*
	for (int i = 0; i < 20; ++i)
		if (i == dc)
			cout << "." << v[i];
		else
			cout << v[i];
	cout << endl;
	*/
	if (ed != -1)
	{
		if (dc == 0)
			fout << "0";
		for (int i = 0; i < ed; ++i)
			if (i == dc)
				fout << "." << v[i];
			else
				fout << v[i];
		if (dc == -1)
			fout << ".0";
		fout << endl;
		fin.close();
		fout.close();
		return 0;
	}

	int hsh = -1;
	int len = -1;
	for (int i = 499999; i >= dc; --i)
	{
		hsh = chash(i,499999);
		len = 500000-i;
		if (check(hsh,i,500000-i))
		{
			//cout << i << endl;
			break;
		}
	}

	for (int i = dc; i < 500000; ++i)
	{
		int tmp = chash(i,i+len-1);
		if (tmp == hsh)
		{
			while (i >= dc)
			{
				int k = i;
				int tmp2 = chash(k,k+len-1);
				k = k+len;
				bool rep = true;
				for (int j = 0; j < 5; ++j)
					if (chash(k,k+len-1) != tmp2)
					{
						rep = false;
						break;
					}
					else
						k = k+len;
				if (rep)
					i = i-1;
				else
					break;
			}
			i = i+1;
			int l = 0;
			for (int k = 0; k <= i+len-1; ++k, ++l)
			{
				int tmp = 10;
				for (int i = 0; i < 10; ++i,++l)
					if (v[k] >= tmp)
						tmp = tmp*10;
					else
						break;
				if (l != 0 && l%76 == 0)
					fout << endl;
				if (k == dc)
				{
					fout << ".";
					++l;
				}
				if (k == i)
				{
					fout << "(" << v[k];
					++l;
				}
				else
					fout << v[k];
				if (k == i+len-1)
				{
					fout << ")" << endl;
					fin.close();
					fout.close();
					return 0;
				}
			}
		}
	}
	fin.close();
	fout.close();

	return 0;
}