#include <iostream>
using namespace std;

int N, M, Q, mat[105][105], query[10005][4];

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> query[i][0];
		if (query[i][0] != 3)
			cin >> query[i][1];
		else
			cin >> query[i][1] >> query[i][2] >> query[i][3];
	}
	for (int i = Q-1; i >= 0; --i) {
		if (query[i][0] == 1) {
			int tmp = mat[query[i][1]][M];
			for (int j = M; j > 1; --j)
				mat[query[i][1]][j] = mat[query[i][1]][j-1];
			mat[query[i][1]][1] = tmp;
		}
		else if (query[i][0] == 2) {
			int tmp = mat[N][query[i][1]];
			for (int j = N; j > 1; --j)
				mat[j][query[i][1]] = mat[j-	1][query[i][1]];
			mat[1][query[i][1]] = tmp;
		}
		else {
			mat[query[i][1]][query[i][2]] = query[i][3];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}