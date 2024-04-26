#include <iostream>
#include <vector>
using namespace std;

int n, m;
void dfs(int depth, vector<int> res) {
	if (depth == m) {
		for (int i : res) cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		res.push_back(i);
		dfs(depth + 1, res);
		res.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> res;
	cin >> n >> m;
	dfs(0, res);
}