#include <iostream>
#include <cstdio>
using namespace std;

int N, Q, oshift, eshift, odd[500005], even[500005];
bool oddfirst = true;

int main() {
	//ios::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 0; i < Q; ++i) {
		int t; scanf("%d",&t);
		if (t == 1) {
			int s; scanf("%d",&s);
			if (s < 0)
				s = (s%N+N)%N;
			if (oddfirst) {
				oshift = (oshift+s/2)%N;
				eshift = (eshift+(s+1)/2)%N;
			}
			else {
				oshift = (oshift+(s+1)/2)%N;
				eshift = (eshift+s/2)%N;
			}
			if (s%2 != 0)
				oddfirst = !oddfirst;
		}
		else {
			oddfirst = !oddfirst;
		}
	}
	for (int i = 0; i < N/2; ++i) {
		odd[i] = 2*i+1;
		even[i] = 2*i+2;
	}
	for (int i = 0; i < N/4; ++i) {
		int tmp = odd[i];
		odd[i] = odd[N/2-1-i];
		odd[N/2-1-i] = tmp;
		tmp = even[i];
		even[i] = even[N/2-1-i];
		even[N/2-1-i] = tmp;
	}
	oshift = (oshift%(N/2)+N/2)%(N/2);
	eshift = (eshift%(N/2)+N/2)%(N/2);
	for (int i = 0; i < oshift/2; ++i) {
		int tmp = odd[i];
		odd[i] = odd[oshift-1-i];
		odd[oshift-1-i] = tmp;
	}
	for (int i = 0; i < eshift/2; ++i) {
		int tmp = even[i];
		even[i] = even[eshift-1-i];
		even[eshift-1-i] = tmp;
	}
	for (int i = 0; i < (N/2-oshift)/2; ++i) {
		int tmp = odd[i+oshift];
		odd[i+oshift] = odd[N/2-1-i];
		odd[N/2-1-i] = tmp;
	}
	for (int i = 0; i < (N/2-eshift)/2; ++i) {
		int tmp = even[i+eshift];
		even[i+eshift] = even[N/2-1-i];
		even[N/2-1-i] = tmp;
	}
	if (oddfirst)
		for (int i = 0; i < N/2; ++i)
			printf("%d %d ",odd[i],even[i]);
	else
		for (int i = 0; i < N/2; ++i)
			printf("%d %d ",even[i],odd[i]);
	cout << endl;
}