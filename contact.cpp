/*
ID: wgan8561
PROG: contact
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int a, b, n, cnt[5000][13];
string str;

struct f
{
    int freq, l, v;
    bool operator<(const f &x)const
    {
        if (freq > x.freq)
            return false;
        else if (x.freq > freq)
            return true;
        if (l < x.l)
            return false;
        if (x.l < l)
            return true;
        if (v < x.v)
            return false;
        return true;
    }
};

priority_queue<f> pq;
 
int main()
{
  	ios_base::sync_with_stdio(0);
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);

    cin >> a >> b >> n;
    string tstr;
    while (getline(cin,tstr))
    {
        //cout << "m8" << endl;
        str = str+tstr;
        //cout << str << endl;
    }
    
    //cout << "awd" << endl;
    //cout << str << endl;
    for (int i = a; i <= b; ++i)
    {
    	int nm = 0;
    	int pw = 1;
    	if (i > str.size())
    		continue;
    	for (int j = 0; j < i; ++j)
    	{
    		pw *= 2;
    		nm *= 2;
    		nm += str[j]-'0';
    	}
        pw /= 2;
    	++cnt[nm][i];
    	for (int j = i; j < str.size(); ++j)
    	{
    		nm = (nm-nm/pw*pw)*2+str[j]-'0';
    		++cnt[nm][i];
    	}
    }

    for (int i = a; i <= b; ++i)
    {
        for (int j = 0; j < 5000; ++j)
        {
            f tmp;
            tmp.freq = cnt[j][i];
            tmp.l = i;
            tmp.v = j;
            if (cnt[j][i] > 0)
                pq.push(tmp);
        }
    }

    int k = 0;
    int freq = -1;
    int cntFreq = 0;
    while (k <= n && pq.size() > 0)
    {
        f tmp = pq.top();
        pq.pop();
        if (tmp.freq != freq)
        {
            if (cntFreq != 0)
                cout << endl;
            ++k;
            if (k > n)
                break;
            freq = tmp.freq;
            cntFreq = 0;
            cout << freq;
        }
        if (cntFreq%6 == 0)
            cout << endl;
        if (cntFreq%6 != 0)
            cout << " ";
        ++cntFreq;
        int dec = tmp.v;
        long long bin = 0LL;
        long long pw = 1LL;
        int ct = 0;
        //cout << dec << " ";
        while (dec != 0)
        {
            bin += dec%2*pw;
            pw *= 10;
            ++ct;
            dec /= 2;
        }
        //cout << tmp.l << " " << ct << " ";
        for (int i = ct; i < tmp.l; ++i)
        {
            cout << 0;
        }
        if (tmp.v != 0)
            cout << bin;
    }
    if (pq.size() == 0)
        cout << endl;
 	fclose(stdin);
 	fclose(stdout);
    return 0;
}