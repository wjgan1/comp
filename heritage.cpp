/*
ID: wgan8561
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;

string in, pre;
int in_pos[26], pre_pos[26], curr;
char tree[1000000];

void printout(int n)
{
	if (tree[n] == '\0')
		return;
	printout(2*n);
	printout(2*n+1);
	cout << tree[n];
}

int main()
{
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	cin >> in >> pre;
	for (int i = 0; i < in.size(); ++i)
		in_pos[in[i]-'A'] = pre_pos[pre[i]-'A'] = i;
	
	curr = 1;
	for (int i = 0; i < pre.size()-1; ++i)
	{
		tree[curr] = pre[i];
		int poss = curr/2;
		while (poss)
		{
			if (in_pos[pre[i+1]-'A'] > in_pos[tree[poss]-'A'] && tree[2*poss+1] == '\0')
				curr = poss;
			poss = poss/2;
		}
		if (in_pos[pre[i+1]-'A'] < in_pos[tree[curr]-'A'])
			curr = curr*2;
		else
			curr = curr*2+1;
	}
	tree[curr] = pre[pre.size()-1];
	
	printout(1);
	cout << endl;
}