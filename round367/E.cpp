#include <iostream>
using namespace std;

typedef pair<int,int> pi;

#define endl '\n'
#define N 1
#define W 2
#define E 3
#define S 4
#define x first
#define y second

int n, m, Q, mat[1005][1005][5][2];
pi root;

pi getP(int i, int j, int d) {
	return make_pair(mat[i][j][d][0],mat[i][j][d][1]);
}

void setP(int i, int j, int d, int ii, int jj) {
	mat[i][j][d][0] = ii;
	mat[i][j][d][1] = jj;
}

void updateP(int i, int j, int d) {
	pi p = getP(i,j,d);
	setP(p.x,p.y,5-d,i,j);
}

void swapP(int i1, int j1, int i2, int j2, int d) {
	pi tmp1 = getP(i1,j1,d);
	pi tmp2 = getP(i2,j2,d);
	setP(i1,j1,d,tmp2.x,tmp2.y);
	setP(i2,j2,d,tmp1.x,tmp1.y);
	updateP(i1,j1,d);
	updateP(i2,j2,d);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> Q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j][0][0];
			setP(i,j,N,i-1,j);
			updateP(i,j,N);
			setP(i,j,W,i,j-1);
			updateP(i,j,W);
		}
	}
	root = make_pair(1,1);
	for (int i = 0; i < Q; ++i) {
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;
		pi p = root, q = root;
		for (int j = 1; j < a; ++j)
			p = getP(p.x,p.y,S);
		for (int j = 1; j < b; ++j)
			p = getP(p.x,p.y,E);
		for (int j = 1; j < c; ++j)
			q = getP(q.x,q.y,S);
		for (int j = 1; j < d; ++j)
			q = getP(q.x,q.y,E);
		pi pcpy = p, qcpy = q;
		if (p == root)
			root = q;
		else if (q == root)
			root = p;
		for (int j = 1; j <= w; ++j) {
			swapP(p.x,p.y,q.x,q.y,N);
			if (j < w) {
				p = getP(p.x,p.y,E);
				q = getP(q.x,q.y,E);
			}
		}
		for (int j = 1; j <= h; ++j) {
			swapP(p.x,p.y,q.x,q.y,E);
			if (j < h) {
				p = getP(p.x,p.y,S);
				q = getP(q.x,q.y,S);
			}
		}
		p = pcpy, q = qcpy;
		for (int j = 1; j <= h; ++j) {
			swapP(p.x,p.y,q.x,q.y,W);
			if (j < h) {
				p = getP(p.x,p.y,S);
				q = getP(q.x,q.y,S);
			}
		}
		for (int j = 1; j <= w; ++j) {
			swapP(p.x,p.y,q.x,q.y,S);
			if (j < w) {
				p = getP(p.x,p.y,E);
				q = getP(q.x,q.y,E);
			}
		}
	}
	for (pi i = root; mat[i.x][i.y][0][0] != 0; i = getP(i.x,i.y,S)) {
		for (pi j = i; mat[j.x][j.y][0][0] != 0; j = getP(j.x,j.y,E))
			cout << mat[j.x][j.y][0][0] << " ";
		cout << endl;
	}
}