#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int sum = 0;
	int mn = 101;
	int num;
	
	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (num & 1)
		{
			sum += num;
			mn = min(num, mn);
		}
	}

	if (mn == 101) cout << -1 << '\n';
	else cout << sum << '\n' << mn << '\n';

	return 0;
}