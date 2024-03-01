#include <iostream>

using namespace std;

char m[6][6];
int r, c, k;
int visited[6][6];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int result;
void DFS(int y, int x, int depth) {
	if (depth == k) {
		if (y == 1 && x == c) result++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || nx<1 || ny>r || nx>c) continue;
		if (m[ny][nx] == 'T'||visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx, depth + 1);
		visited[ny][nx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> m[i][j];
		}
	}
	visited[r][1] = 1;
	DFS(r, 1, 1);
	cout << result << '\n';
}