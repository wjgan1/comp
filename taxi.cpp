#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int arr[3];
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = 0;
	}
	int ans;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 4)
			++ans;
		else
			++arr[tmp-1];
	}

	N = N-ans;
	int spaces_left;
	while (N > 0)
	{
		spaces_left = 4;
		for (int i = 2; i >= 0; --i)
		{
			if (arr[i] > 0)
			{
				int tmp = spaces_left/(i+1);
				if (tmp > arr[i])
				{
					tmp = arr[i];
					spaces_left -= (i+1)*tmp;
				}
				else
					spaces_left = spaces_left%(i+1);
				arr[i] -= tmp;
				N -= tmp;
			}
		}
		++ans;
	}

	cout << ans << endl;
	return 0;
}