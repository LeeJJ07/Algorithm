#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;

void dfs(int start) {
	if (result.size() == m) {
		for (int num : result) cout << num << ' ';
		cout << '\n';
		return;
	}
	for (int i = start + 1; i <= n; i++) {
		result.push_back(i);
		dfs(i);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	dfs(0);
}