#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	list<int> arr;
	vector<int> res;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		arr.push_back(i + 1);

	auto it = arr.begin();
	for (int i = 0; i < K - 1; i++)
		it++;

	while (true)
	{
		res.push_back(*it);
		it = arr.erase(it);
		if (it == arr.end()) it = arr.begin();
		if (arr.empty())break;

		for (int i = 0; i < K - 1; i++)
		{
			it++;
			if (it == arr.end())
				it = arr.begin();
		}
	}
	
	cout << "<";
	for (int i = 0; i < res.size() - 1; i++)
		cout << res[i] << ", ";
	cout << res[res.size() - 1] << ">\n";

	return 0;
}