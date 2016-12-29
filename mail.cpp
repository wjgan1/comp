#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[200005];

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	cout << arr[1]-arr[0] << " " << arr[N-1]-arr[0] << endl;
	for (int i = 1; i < N-1; ++i)
		printf("%d %d\n",min(arr[i]-arr[i-1],arr[i+1]-arr[i]),max(arr[i]-arr[0],arr[N-1]-arr[i]));
	cout << arr[N-1]-arr[N-2] << " " << arr[N-1]-arr[0] << endl;
}