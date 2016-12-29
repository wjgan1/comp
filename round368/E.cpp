#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

#define endl '\n'
#define x first
#define y second

pi gar[2005][2005], grid[2005][2005];
ll pref[2005][2005];
int N, M, K, Q, len[2005];
bool off[2005];
vector<int> mark[2005];

bool within(pi p, int x1, int y1, int x2, int y2) {
	if (p.x < x1 || p.x > x2)
		return false;
	if (p.y < y1 || p.y > y2)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 1; i <= K; ++i) {
		cin >> len[i];
		for (int j = 1; j <= len[i]; ++j) {
			scanf("%d %d",&(gar[i][j].x),&(gar[i][j].y));
			grid[gar[i][j].x][gar[i][j].y] = make_pair(i,j);
			cin >> pref[i][j];
			pref[i][j] += pref[i][j-1];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string cmd; scanf("%s",&cmd[0]);
		if (cmd == "SWITCH") {
			int k; cin >> k;
			off[k] = !off[k];
		}
		else {
			int x1, y1, x2, y2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			ll light = 0;
			for (int j = x1; j <= x2; ++j) {
				pi p1 = grid[j][y1], p2 = grid[j][y2];
				mark[p1.x].push_back(p1.y);
				if (p1.x != 0 && !off[p1.x])
					light += pref[p1.x][p1.y]-pref[p1.x][p1.y-1];
				if (y1 != y2) {
					mark[p2.x].push_back(p2.y);
					if (p2.x != 0 && !off[p2.x])
						light += pref[p2.x][p2.y]-pref[p2.x][p2.y-1];
				}
			}
			for (int j = y1+1; j < y2; ++j) {
				pi p1 = grid[x1][j], p2 = grid[x2][j];
				mark[p1.x].push_back(p1.y);
				if (p1.x != 0 && !off[p1.x])
					light += pref[p1.x][p1.y]-pref[p1.x][p1.y-1];
				if (x1 != x2) {
					mark[p2.x].push_back(p2.y);
					if (p2.x != 0 && !off[p2.x])
						light += pref[p2.x][p2.y]-pref[p2.x][p2.y-1];
				}
			}
			for (int k = 1; k <= K; ++k) {
				if (off[k]) {
					mark[k].resize(0);
					continue;
				}
				if (mark[k].size() == 0 && within(gar[k][1],x1,y1,x2,y2))
					light += pref[k][len[k]];
				else if (mark[k].size() > 0) {
					sort(mark[k].begin(),mark[k].end());
					for (int j = 0; j < mark[k].size()-1; ++j) {
						if (mark[k][j+1]-mark[k][j] > 1 && within(gar[k][mark[k][j]+1],x1,y1,x2,y2))
							light += pref[k][mark[k][j+1]-1]-pref[k][mark[k][j]];
					}
					if (within(gar[k][1],x1,y1,x2,y2))
						light += pref[k][mark[k][0]-1];
					if (within(gar[k][len[k]],x1,y1,x2,y2))
						light += pref[k][len[k]]-pref[k][mark[k][mark[k].size()-1]];
				}
				mark[k].resize(0);
			}
			mark[0].resize(0);
			cout << light << endl;
		}
	}
}