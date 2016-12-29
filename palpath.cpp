#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int N;
ll ans;
string grid[505];
vector<vector<ll> > *pa;

int idx(int x, int y) {
	if (x+y >= N)
		return N-1-y;
	return x;
}

pair<int,int> pnt(int d, int idx) {
	if (d < 0)
		return make_pair(N-1+(d+1)+idx,N-1-idx);
	return make_pair(idx,d-idx);
}

int main()
{
	freopen("palpath.in","r",stdin);
	freopen("palpath.out","w",stdout);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> grid[i];

	if (grid[0][0] != grid[N-1][N-1]) {
		cout << 0 << endl;
		return 0;
	}
	pa = new vector<vector<ll> >(N);
	for (int i = 0; i < N; ++i) {
		(*pa)[i].resize(N);
		for (int j = 0; j < N; ++j)
			(*pa)[i][j] = 0;
	}
	(*pa)[idx(0,0)][idx(N-1,N-1)] = 1;
	for (int i = 0; i < N-1; ++i) {
		vector<vector<ll> > *npa = new vector<vector<ll> >(N);
		for (int i = 0; i < N; ++i) {
			(*npa)[i].resize(N);
			for (int j = 0; j < N; ++j)
				(*npa)[i][j] = 0;
		}
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= i; ++k) {
				if ((*pa)[j][k] != 0) {
					int x1 = pnt(i,j).first;
					int y1 = pnt(i,j).second;
					int x2 = pnt(-i-1,k).first;
					int y2 = pnt(-i-1,k).second;
					if (grid[x1+1][y1] == grid[x2-1][y2]) {
						int idx1 = idx(x1+1,y1);
						int idx2 = idx(x2-1,y2);
						(*npa)[idx1][idx2] = ((*npa)[idx1][idx2]+(*pa)[j][k])%1000000007;
					}
					if (grid[x1+1][y1] == grid[x2][y2-1]) {
						int idx1 = idx(x1+1,y1);
						int idx2 = idx(x2,y2-1);
						(*npa)[idx1][idx2] = ((*npa)[idx1][idx2]+(*pa)[j][k])%1000000007;
					}
					if (grid[x1][y1+1] == grid[x2-1][y2]) {
						int idx1 = idx(x1,y1+1);
						int idx2 = idx(x2-1,y2);
						(*npa)[idx1][idx2] = ((*npa)[idx1][idx2]+(*pa)[j][k])%1000000007;
					}
					if (grid[x1][y1+1] == grid[x2][y2-1]) {
						int idx1 = idx(x1,y1+1);
						int idx2 = idx(x2,y2-1);
						(*npa)[idx1][idx2] = ((*npa)[idx1][idx2]+(*pa)[j][k])%1000000007;
					}
				}
			}
		}
		delete pa;
		pa = npa;
	}
	for (int i = 0; i < N; ++i)
		ans = (ans+(*pa)[i][i])%1000000007;
	cout << ans << endl;
}