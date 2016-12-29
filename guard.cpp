#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct cow
{
	int h, w, s;
	bool operator<(const cow &rhs) const
	{
		if (s > rhs.s)
			return true;
		else if (s < rhs.s)
			return false;
		return (w > rhs.w);
	}
};

int N, H, S = -1;
cow arr[25];
vector<int> v;

void check()
{
	if (v.size() == 0)
		return;
	/*
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	*/
	int h = arr[v[0]].h;
	int w = arr[v[0]].s;
	//cout << h << endl;
	for (int i = 1; i < v.size(); ++i)
	{
		//cout << w << endl;
		if (arr[v[i]].w > w)
			return;
		else
			w = min(w-arr[v[i]].w,arr[v[i]].s);
		h += arr[v[i]].h;
	}
	if (h >= H)
		S = max(S,w);
	//cout << "m8 " <<  w << endl;
}

void gen(int p)
{
	v.push_back(p);
	check();
	//cout << p << endl;
	if (p == N-1)
	{
		v.resize(v.size()-1);
		return;
	}
	for (int i = p+1; i < N; ++i)
		gen(i);
	v.resize(v.size()-1);
}

int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	cin >> N >> H;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].h >> arr[i].w >> arr[i].s;
	sort(arr,arr+N);
	//for (int i = 0; i < N; ++i)
	//	cout << arr[i].h << " " << arr[i].w << " " << arr[i].s << endl;
	for (int i = 0; i < N; ++i)
		gen(i);
	if (S == -1)
		cout << "Mark is too tall" << endl;
	else
		cout << S << endl;
}