#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

#define endl '\n'
#define A (2*M_PI)

int N;
ll V, T, cir[100005][3];
double ans;
vector<pair<double,bool> > v;

int main() {
	ios::sync_with_stdio(false);
	cin >> cir[0][0] >> cir[0][1] >> V >> T;
	cir[0][2] = V*T;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> cir[i][0] >> cir[i][1] >> cir[i][2];
	}
	double r0 = 1.0*cir[0][2]*cir[0][2];
	//cout << r0 << endl;
	for (int i = 1; i <= N; ++i) {
		ll dx = cir[i][0]-cir[0][0], dy = cir[i][1]-cir[0][1];
		double dd = 1.0*dx*dx+1.0*dy*dy;
		double d = sqrt(dd);
		if (abs(d-cir[i][2]) <= 1e-10 || d <= cir[i][2]) {
			cout << 1 << endl;
			return 0;
		}
		if (d >= cir[0][2]+cir[i][2])
			continue;
		double dang, ang;
		double ri = 1.0*cir[i][2]*cir[i][2];
		if (dd-ri <= r0)
			dang = asin(cir[i][2]/d);
		else
			dang = acos((ri-r0-dd)/(-2*cir[0][2]*d));
		if (cir[i][0]-cir[0][0] >= 0) {
			ang = asin((cir[i][1]-cir[0][1])/d);
			if (ang < 0)
				ang += A;
		}
		else {
			ang = M_PI-(asin((cir[i][1]-cir[0][1])/d));
		}
		//cout << ang << " " << dang << endl;
		double s = ang-dang, f = ang+dang;
		//cout << s << " " << f << endl;
		if (abs(s-0) <= 1e-10)
			s = 0;
		if (abs(f-A) <= 1e-10)
			f = A;
		if (s >= 0 && f <= A) {
			v.push_back(make_pair(s,1));
			v.push_back(make_pair(f,0));
		}
		else if (s >= 0) {
			v.push_back(make_pair(s,1));
			v.push_back(make_pair(A,0));
			v.push_back(make_pair(0,1));
			v.push_back(make_pair(f-A,0));
		}
		else {
			v.push_back(make_pair(s+A,1));
			v.push_back(make_pair(A,0));
			v.push_back(make_pair(0,1));
			v.push_back(make_pair(f,0));
		}
	}
	sort(v.begin(),v.end());
	double begin = 0;
	for (int i = 0, cnt = 0; i < v.size(); ++i) {
		//cout << v[i].first << " " << v[i].second << endl;
		if (v[i].second) {
			if (cnt++ == 0)
				begin = v[i].first;
		}
		else {
			if (--cnt == 0)
				ans += v[i].first-begin;
		}
		//cout << ans << endl;
	}
	//cout << ans << endl;
	cout << ans/A << endl;
}