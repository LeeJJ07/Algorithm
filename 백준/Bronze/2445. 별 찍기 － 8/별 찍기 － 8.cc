#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < 2 * N - 1; i++)
	{
		int temp = 2 * N - 2 - i;
		int j = abs(temp - i);
		for (int k = 0; k < 2 * N; k++)
		{
			if (k >= N - j / 2 && k < N + j / 2)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}