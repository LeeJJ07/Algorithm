#include <iostream>
using namespace std;

int R, C;
char m[24][24];
int check[26];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int result = 0;

void DFS(int y, int x, int level) {
	if (result < level) result = level;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || nx<1 || ny>R || nx>C || check[m[ny][nx] - 'A'])continue;
		check[m[ny][nx] - 'A'] = 1;
		DFS(ny, nx, level + 1);
		check[m[ny][nx] - 'A'] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> m[i][j];
		}
	}
	check[m[1][1] - 'A']++;
	DFS(1, 1, 1);
	cout << result << '\n';
}