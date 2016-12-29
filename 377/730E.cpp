#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans, U, c[200005], s[200005]; //last two for printing at the end
pair<int,int> comp[200005], sock[200005];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		comp[i].second = i;
		cin >> comp[i].first;
	}
	for (int i = 0; i < M; i++) {
		cin >> sock[i].first;
		sock[i].second = i;
	}
	sort(comp,comp+N);
	sort(sock,sock+M);
	int u = 0;
	bool cont;
	do {
		int i = 0, j = 0;
		while (i < N && j < M) {
			if (comp[i].first == -1)
				i++;
			else if (sock[j].first == -1)
				j++;
			else if (comp[i].first == sock[j].first) {
				c[comp[i].second] = sock[j].second+1;
				comp[i].first = sock[j].first = -1;
				s[sock[j].second] = u;
				i++;
				j++;
				ans++;
				U += u;
			}
			else if (comp[i].first < sock[j].first)
				i++;
			else
				j++;
		}
		cont = false;
		for (int k = 0; k < M; k++) {
			if (abs(sock[k].first) > 1) {
				cont = true;
				sock[k].first = (sock[k].first+1)/2;
			}
		}
		++u;
	}
	while (cont);
	cout << ans << " " << U << endl;
	for (int i = 0; i < M; i++)
		cout << s[i] << endl;
	for (int i = 0; i < N; i++)
		cout << c[i] << endl;
}