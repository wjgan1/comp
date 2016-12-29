#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
typedef double dd;

#define endl '\n'
#define xx first
#define yy second

int N;
ll S, MA;
pair<ll,ll> p[5005], t[3];
vector<pair<ll,ll> > hull;

bool cnvx(pair<ll,ll> l, pair<ll,ll> r) {
	return (l.xx-p[0].xx)*(r.yy-p[0].yy)-(l.yy-p[0].yy)*(r.xx-p[0].xx) > 0;
}

pair<dd,dd> itsct(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) {
	if (b1 == 0) {
		if (a2 == 0) 
			return make_pair(c1/a1,c2/b2);
		return make_pair(-1.0*c1/a1,(-c2+1.0*a2*c1/a1)/b2);
	}
	if (b2 == 0) {
		if (a1 == 0)
			return make_pair(c2/a2,c1/b1);
		return make_pair(-1.0*c2/a2,(-c1+1.0*a1*c2/a2)/b1);
	}
	dd x = (1.0*c2*b1-1.0*c1*b2)/(1.0*a1*b2-1.0*a2*b1);
	return make_pair(x,(-c1-a1*x)/b1);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> p[i].xx >> p[i].yy;
	sort(p,p+N);
	hull.push_back(p[0]);
	sort(p+1,p+N,cnvx);
	hull.push_back(p[1]);
	for (int i = 2; i < N; ++i) {
		while (hull.size() >= 2 && (p[i].xx-hull[hull.size()-1].xx)*(hull[hull.size()-1].yy-hull[hull.size()-2].yy)
		-(p[i].yy-hull[hull.size()-1].yy)*(hull[hull.size()-1].xx-hull[hull.size()-2].xx) >= 0)
			hull.resize(hull.size()-1);
		hull.push_back(p[i]);
	}
	/*
	for (int i = 0; i < hull.size(); ++i) {
		cout << hull[i].xx << " " << hull[i].yy << endl;
	}
	*/
	for (int i = 0; i < hull.size(); ++i) {
		for (int j = i+1, k = i+2; j < hull.size() && k < hull.size(); ++j) {
			ll dx = hull[j].xx-hull[i].xx, dy = hull[j].yy-hull[i].yy;
			ll mh = abs(-dy*(hull[k].xx-hull[i].xx)+dx*(hull[k].yy-hull[i].yy)), h;
			while (k < hull.size()-1 && (h = abs(-dy*(hull[k+1].xx-hull[i].xx)
			+dx*(hull[k+1].yy-hull[i].yy))) > mh) {
				mh = h;
				++k;
			}
			ll A;
			if ((A = mh/2) > MA) {
				MA = A;
				t[0] = hull[i];
				t[1] = hull[j];
				t[2] = hull[k];
			}
		}
	}
	ll a1 = t[0].yy-t[1].yy, b1 = -(t[0].xx-t[1].xx), c1 = -b1*t[2].yy-a1*t[2].xx;
	ll a2 = t[1].yy-t[2].yy, b2 = -(t[1].xx-t[2].xx), c2 = -b2*t[0].yy-a2*t[0].xx;
	ll a3 = t[0].yy-t[2].yy, b3 = -(t[0].xx-t[2].xx), c3 = -b3*t[1].yy-a3*t[1].xx;
	//cout << a1 << " " << b1 << " " << c1 << endl;
	pair<dd,dd> t1 = itsct(a1,b1,c1,a2,b2,c2);
	pair<dd,dd> t2 = itsct(a1,b1,c1,a3,b3,c3);
	pair<dd,dd> t3 = itsct(a3,b3,c3,a2,b2,c2);
	//cout << endl;
	cout << (ll)t1.xx << " " << (ll)t1.yy << endl;
	cout << (ll)t2.xx << " " << (ll)t2.yy << endl;
	cout << (ll)t3.xx << " " << (ll)t3.yy << endl;
	/*
	cout << t2.xx << " " << t2.yy << endl;
	cout << t3.xx << " " << t3.yy << endl;
	*/
}