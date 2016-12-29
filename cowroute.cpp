#include <fstream>
#include <iostream>

using namespace std;

class Route
{
public:
	int cost;
	int N;
	int [] stops;
}

int main()
{
	int A;
	int B;
	int N;
	ifstream in("cowroute.in");
	ofstream out("cowroute.out");
	in >> A >> B >> N;

	int arr[N][502];

	int lowest = -1;
	for(int i = 0; i < N; ++i)
	{
		int cost;
		int routes;
		in >> cost >> routes;
		arr[i][500] = cost;
		arr[i][501] = routes;
		int a = -1;
		int b = -1;
		for (int j = 0; j < routes; ++j)
		{
			int tmp;
			in >> tmp;
			arr[i][j] = tmp;
			if (tmp == A)
				a = j;
			else if (tmp == B)
				b = j;
		}
		if (b != -1 && a != -1 && b > a)
		{
			int tmp = cost;
			if (tmp < lowest || lowest == -1)
				lowest = tmp;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int a = -1;
			int b = -1;
			for (int k = 0; arr[k] != 0; ++k)
			{
				
			}
		}
	}

	out << lowest;
}