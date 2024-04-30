#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> node;

int m[9][9];
vector<node> v;
bool check(int idx, int num) {
	int y = v[idx].first;
	int x = v[idx].second;

	for (int i = 0; i < 9; i++) {
		if (m[y][i] == num) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (m[i][x] == num) return false;
	}
	y /= 3, x /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (m[i + 3 * y][j + 3 * x] == num) return false;
		}
	}
	return true;
}
void dfs(int idx) {
	if (idx == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << m[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {
		if (!check(idx, i)) continue;
		m[v[idx].first][v[idx].second] = i;
		dfs(idx + 1);
		m[v[idx].first][v[idx].second] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> m[i][j];
			if (!m[i][j]) v.push_back({ i, j });
		}
	}
	dfs(0);
}