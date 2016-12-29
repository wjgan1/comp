#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

#define endl '\n'

bool vis[505][505];
int N, K, grid[505][505], tsz, cc[250005], sz[250005], ans;

void dfs(int i, int j, int k) {
	if (i < 1 || i > N || j < 0 || j > N)
		return;
	if (vis[i][j] || grid[i][j] == 0)
		return;
	vis[i][j] = true;
	grid[i][j] = k;
	++sz[k];
	dfs(i-1,j,k);
	dfs(i+1,j,k);
	dfs(i,j-1,k);
	dfs(i,j+1,k);
}

void add(int i, int j) {
	if (grid[i][j] != 0) {
		if (cc[grid[i][j]]++ == 0)
			tsz += sz[grid[i][j]];
	}
	else {
		tsz++;
		if (cc[grid[i-1][j]]++ == 0)
			tsz += sz[grid[i-1][j]];
		if (cc[grid[i+1][j]]++ == 0)
			tsz += sz[grid[i+1][j]];
		if (cc[grid[i][j-1]]++ == 0)
			tsz += sz[grid[i][j-1]];
		if (cc[grid[i][j+1]]++ == 0)
			tsz += sz[grid[i][j+1]];
	}
}

void remove(int i, int j) {
	if (grid[i][j] != 0) {
		if (--cc[grid[i][j]] == 0)
			tsz -= sz[grid[i][j]];
	}
	else {
		tsz--;
		if (--cc[grid[i-1][j]] == 0)
			tsz -= sz[grid[i-1][j]];
		if (--cc[grid[i+1][j]] == 0)
			tsz -= sz[grid[i+1][j]];
		if (--cc[grid[i][j-1]] == 0)
			tsz -= sz[grid[i][j-1]];
		if (--cc[grid[i][j+1]] == 0)
			tsz -= sz[grid[i][j+1]];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j)
			grid[i][j+1] = str[j] == 'X' ? 0 : 1;
	}
	for (int i = 1, k = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!vis[i][j] && grid[i][j] != 0) {
				dfs(i,j,k);
				++k;
			}
		}
	}
	for (int i = K; i <= N; ++i) {
		tsz = 0;
		for (int j = 1; j <= K; ++j) {
			for (int k = i-K+1; k <= i; ++k)
				add(k,j);
		}
		ans = max(ans,tsz);
		for (int j = K+1; j <= N; ++j) {
			for (int k = i-K+1; k <= i; ++k) {
				remove(k,j-K);
				add(k,j);
			}
			ans = max(ans,tsz);
		}
		for (int j = N-K+1; j <= N; ++j) {
			for (int k = i-K+1; k <= i; ++k)
				remove(k,j);
		}
	}
	cout << ans << endl;
}