#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;

	int cnt[9] = { 0 };
	while (num > 0)
	{
		if (num % 10 == 9) cnt[6]++;
		else cnt[num % 10]++;
		num /= 10;
	}
	
	int res = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 6) res = max(cnt[i] / 2 + (cnt[i] % 2 ? 1 : 0), res);
		else res = max(res, cnt[i]);
	}

	cout << res << '\n';

	return 0;
}