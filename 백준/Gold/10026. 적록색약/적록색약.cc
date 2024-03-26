#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, level1, level2;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };
char a[104][104];
int visited[104][104];

void dfs(int y, int x, int level, char c) {
	visited[y][x] = level;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		if (a[ny][nx] != c) continue;
		dfs(ny, nx, level, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			level1++;
			dfs(i, j, level1, a[i][j]);
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'G') a[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			level2++;
			dfs(i, j, level2, a[i][j]);
		}
	}
	cout << level1 << ' ' << level2 << '\n';
}