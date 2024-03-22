#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int num[12];
vector<int> a;
int result_max = -1000000004;
int result_min = 1000000004;

void dfs(int idx1, int idx2, int number) {
	if (idx1 == n) {
		result_max = max(result_max, number);
		result_min = min(result_min, number);
		return;
	}
	if (a[idx2] == 0) {
		dfs(idx1 + 1, idx2 + 1, number + num[idx1]);
	}
	else if (a[idx2] == 1) {
		dfs(idx1 + 1, idx2 + 1, number - num[idx1]);
	}
	else if (a[idx2] == 2) {
		dfs(idx1 + 1, idx2 + 1, number * num[idx1]);
	}
	else if (a[idx2] == 3) {
		if (number < 0) {
			dfs(idx1 + 1, idx2 + 1, -((-number) / num[idx1]));
		}
		else {
			dfs(idx1 + 1, idx2 + 1, number / num[idx1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) {
		int b; cin >> b;
		for (int j = 0; j < b; j++) {
			a.push_back(i);
		}
	}
	do {
		dfs(1, 0, num[0]);
	} while (next_permutation(a.begin(), a.end()));
	cout << result_max << '\n';
	cout << result_min << '\n';
}