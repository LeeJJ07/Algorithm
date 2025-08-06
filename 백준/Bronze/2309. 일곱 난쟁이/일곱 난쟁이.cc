#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sum = 0;
vector<int> arr(9), res;

void FindDwarfs() {
	for (int i = 0; i < 8;i++) {
		for (int j = i + 1;j < 9;j++) {
			if (arr[i] + arr[j] != sum)
				continue;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j)
					continue;
				res.push_back(arr[k]);
			}
			return;
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9;i++) {
		cin >> arr[i]; sum += arr[i];
	}
	sum -= 100;

	FindDwarfs();
	sort(res.begin(), res.end());

	for (int r : res)
		cout << r << '\n';
}