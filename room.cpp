#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int inroom[1000005];
vector<pair<int,int> > room(300);

int main()
{
	cin >> N;
	for (int i = N-1; i >= 0; --i)
	{
		string blank; cin >> blank;
		cin >> room[i].first;
		room[i].second = blank == "+" ? 1 : -1;
	}
	for (int i = N-1; i >= 0; --i)
	{
		inroom[room[i].first] += room[i].second;
		if (inroom[room[i].first] < 0)
		{
			inroom[room[i].first] = 0;
			room[N] = make_pair(room[i].first,1);
			++N;
		}
	}
	int sum = 0;
	for (int i = N-1; i >= 0; --i)
	{
		//cout << room[i] << endl;

		sum += room[i].second;
		ans = max(ans,sum);
	}
	cout << ans << endl;
}