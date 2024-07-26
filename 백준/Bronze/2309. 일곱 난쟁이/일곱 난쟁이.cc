#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int sum = 0;
	vector<int> arr(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sum -= 100;

	vector<int> res;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (arr[i] + arr[j] != sum) continue;
			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j) continue;
				res.push_back(arr[k]);
			}
			break;
		}
		if (res.size()) break;
	}
	sort(res.begin(), res.end());

	for (int num : res)
		cout << num << '\n';

	return 0;
}