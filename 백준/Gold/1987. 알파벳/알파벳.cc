#include <iostream>
using namespace std;

int r, c;
char a[24][24];
int visited[26];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int result = 0;
void dfs(int y, int x, int depth) {
	if (result < depth) result = depth;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[a[ny][nx]-'A']) continue;
		visited[a[ny][nx]-'A'] = 1;
		dfs(ny, nx, depth + 1);
		visited[a[ny][nx]-'A'] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << result;
}