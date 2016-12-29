/*
ID: wgan8561
PROG:
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
#define in2 ""
#define out1 "data.out"
#define out2 ""

#define M 1000000007
#define P 107

int h[100];
vector<int> hash(1,0);
vector<int> pow(1,1);

int hext(int h, int ch)
{
	return (P*h+ch)%M;
}

int main()
{
	ifstream fin(in1);
	ofstream fout(out1);

	string t;
	h[0] = hext(0,s[0]);
	for (int i = 1; i < t.size(); ++i)
		h[i] = hext(h[i-1],t[i]-'a');

	for (int i = 0; i < s.size(); ++i)
	{
		hash.push_back(hext(hash.back(),s[i]-'a'));
		pow.push_back(pow.back()*P%M);

		if (hash.size() > t.size())
		{
			int hsh = (hash.back()-hash[hash.size()-t.size()])/
		}
	}

	if (hash[s.size()-t.size()]/)

	fin.close();
	fout.close();

	return 0;
}