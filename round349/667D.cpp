#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, far[3005][5], revfar[3005][5], best[4],
gdist[3005][3005], revdist[3005][3005], ans;
vector<vector<int> > g, grev;
bool vis[3005];

void bfs(int u, bool rev, vector<vector<int> > &graph) {
	queue<pair<int,int> > q;
	q.push(make_pair(u,0));
	vector<pair<int,int> > dist;
	while (!q.empty()) {
		int v = q.front().first, d = q.front().second;
		q.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		if (!rev)
			gdist[u][v] = d;
		dist.push_back(make_pair(-1*d,v));
		for (int i = 0; i < graph[v].size(); ++i)
			q.push(make_pair(graph[v][i],d+1));
	}
	sort(dist.begin(),dist.end());
	for (int i = 0; i < 3 && i < dist.size(); ++i) {
		if (!rev)
			far[u][i] = dist[i].second;
		else 
			revfar[u][i] = dist[i].second;
	}
	for (int i = 1; i <= N; ++i)
		vis[i] = false;
}

int main() {
	cin >> N >> M;
	g.resize(N+5);
	grev.resize(N+5);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		grev[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		bfs(i,false,g);
	}
	for (int i = 1; i <= N; ++i) {
		bfs(i,true,grev);
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j || gdist[i][j] == 0)
				continue;
			for (int u = 0; u < 3; ++u) {
				for (int v = 0; v < 3; ++v) {
					if (revfar[i][u] != 0 && far[j][v] != 0 && revfar[i][u] != far[j][v]
						&& revfar[i][u] != j && revfar[i][u] != i && far[j][v] != i && far[j][v] != j) {
						if (gdist[revfar[i][u]][i]+gdist[i][j]+gdist[j][far[j][v]] > ans) {
							ans = gdist[revfar[i][u]][i]+gdist[i][j]+gdist[j][far[j][v]];
							best[0] = revfar[i][u];
							best[1] = i;
							best[2] = j;
							best[3] = far[j][v];
						}
					}
				}
			}
		}
	}
	cout << best[0] << " " << best[1] << " " << best[2] << " " << best[3] << endl;
}