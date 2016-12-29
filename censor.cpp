#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define SIGMA 26

struct trie {
	int children, depth;
	trie* next[SIGMA];
	trie* suff;
	trie()
	{
		children = depth = 0;
		for (int i = 0; i < SIGMA; ++i)
			next[i] = NULL;
		suff = NULL;
	}
};

int N;
string S;
trie root;
queue<pair<trie*,trie*> > q;
vector<char> v;
vector<trie*> lst;

void dfs(trie *node) {
	//cout << node->children << endl;
	cout << node->children << " " << node->depth << " ";
	if (node->suff)
		cout << node->suff->depth << endl;
	else
		cout << endl;
	if (node->children == 0)
		return;
	for (int i = 0; i < SIGMA; ++i) {
		if (node->next[i]) {
			cout << (char)(i+'a') << " ";
			dfs(node->next[i]);
		}
	}
}	

int main() {
	freopen("censor.in","r",stdin);
	freopen("censor.out","w",stdout);

	cin >> S >> N;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		trie* curr = &root;
		for (int j = 0; j < str.size(); curr = curr->next[str[j]-'a'],++j) {
			if (!curr->next[str[j]-'a']) {
				curr->next[str[j]-'a'] = new trie();
				curr->children++;
				curr->depth = j;
			}
		}
		curr->depth = str.size();
	}
	for (int i = 0; i < SIGMA; ++i) {
		if (root.next[i]) {
			q.push(make_pair(&root,root.next[i]));
			root.next[i]->suff = &root;
		}
	}
	while (!q.empty()) {
		trie* match = q.front().first, *cpy;
		trie* curr = q.front().second;
		q.pop();
		if (match->children == 0 || curr->children == 0)
			continue;
		for (int i = 0; i < SIGMA; ++i) {
			if (!curr->next[i])
				continue;
			cpy = match;
			while (true) {
				if (cpy->next[i]) {
					curr->next[i]->suff = cpy->next[i];
					q.push(make_pair(cpy->next[i],curr->next[i]));
					break;
				}
				if (!cpy->suff) {
					curr->next[i]->suff = &root;
					q.push(make_pair(&root,curr->next[i]));
					break;
				}
				cpy = cpy->suff;
			}
		}
	}
	//dfs(&root);
	//cout << "m8" << endl;
	trie *curr = &root;
	for (int i = 0; i < S.size(); ++i) {
		cout << i << " " << S[i] << endl;
		if (curr->children == 0) {
			cout << i << "-" << S[i] << endl;
			v.resize(v.size()-curr->depth);
			lst.resize(lst.size()-curr->depth);
			curr = lst.size() == 0 ? &root : lst[lst.size()-1];
			//cout << "*" << curr->depth << endl;
		}
		if (curr->next[S[i]-'a']) {
			curr = curr->next[S[i]-'a'];
			lst.push_back(curr);
			v.push_back(S[i]);
		}
		else if (curr->suff) {
			curr = curr->suff;
			--i;
		}
		else {
			curr = &root;
			lst.push_back(curr);
			v.push_back(S[i]);
		}
		//cout << i << " " << S[i] << " " << v.size() << " " << curr->depth << endl;
	}
	if (curr->children == 0)
		v.resize(v.size()-curr->depth);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i];
	cout << endl;
}
