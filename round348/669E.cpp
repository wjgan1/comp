#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Q, query[100005][3];
vector<int> *BIT[100005];
map<int,int> val, *moment[100005];

void bit_add(int x, int t, int u) {
	int pos = val[x], idx = (*moment[pos])[t];
	while (idx <= moment[pos]->size()) {	
		(*BIT[pos])[idx] += u;
		idx += idx & -idx;
	}
}

int bit_query(int x, int t) {
	int sum = 0, pos = val[x], idx = (*moment[pos])[t];
	while (idx > 0) {
		sum += (*BIT[pos])[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main() {
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> query[i][0] >> query[i][1] >> query[i][2];
		val[query[i][2]] = 0;
	}
	int idx = 0;
	for (map<int,int>::iterator mit = val.begin(); mit != val.end(); ++mit, ++idx) {
		mit->second = idx;
		moment[idx] = new map<int,int>();
	}
	for (int i = 0; i < Q; ++i)
		(*moment[val[query[i][2]]])[query[i][1]] = 0;
	for (map<int,int>::iterator mit = val.begin(); mit != val.end(); ++mit) {
		BIT[mit->second] = new vector<int>(moment[mit->second]->size()+5);
		for (int i = 1; i <= moment[mit->second]->size(); ++i)
			(*BIT[mit->second])[i] = 0;
		idx = 1;
		for (map<int,int>::iterator mjt = moment[mit->second]->begin();
			mjt != moment[mit->second]->end(); ++mjt, ++idx)
			mjt->second = idx;
	}
	for (int i = 0; i < Q; ++i) {
		if (query[i][0] == 1)
			bit_add(query[i][2],query[i][1],1);
		else if (query[i][0] == 2)
			bit_add(query[i][2],query[i][1],-1);
		else
			cout << bit_query(query[i][2],query[i][1]) << endl;
	}
}