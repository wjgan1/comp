#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll N, A, B, C, D, ans = 0;
	cin >> N >> A >> B >> C >> D;
	ll mi = min(min(A+B,B+D),min(A+C,C+D)), ma = max(max(A+B,B+D),max(A+C,C+D));
	if (mi+N-ma >= 1)
		cout <<(mi+N-ma)*N << endl;
	else
		cout << 0 << endl;
}