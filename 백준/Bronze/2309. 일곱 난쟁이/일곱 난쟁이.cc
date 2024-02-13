#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> height(9);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	sum -= 100;
	bool find = false;
	vector<int> result;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (height[i] + height[j] == sum) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					result.push_back(height[k]);
				}
				find = true;
				break;
			}
		}
		if (find)
			break;
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < 7; i++) {
		cout << result[i] << '\n';
	}
}