#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[54][54];
int visited[54][54];
int level = 1;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

void dfs(int y, int x) {
	vector<int> temp;
	for (int j = 0; j < 4; j++) {
		if (a[y][x] & (1 << j)) continue;
		temp.push_back(j);
	}
	
	for (int i : temp) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		visited[ny][nx] = level;
		dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = level;
			dfs(i, j);
			level++;
		}
	}
	vector<int> count(level);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			count[visited[i][j]]++;
		}
	}
	cout << level - 1 << '\n';
	int result = 0;
	for (int i = 0; i < level; i++) {
		if (result < count[i]) result = count[i];
	}
	cout << result << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m + 1; j++) {
			if ((visited[i][j] != visited[i][j - 1]) && count[visited[i][j]] + count[visited[i][j - 1]] > result)
				result = count[visited[i][j]] + count[visited[i][j - 1]];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if ((visited[j][i] != visited[j-1][i]) && count[visited[j][i]] + count[visited[j-1][i]] > result)
				result = count[visited[j][i]] + count[visited[j-1][i]];
		}
	}
	cout << result << '\n';
}