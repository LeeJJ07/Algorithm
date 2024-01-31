#include <iostream>
#include <queue>
using namespace std;

static int N, M;
static int dx[] = { 0, -1, 0, 1 };
static int dy[] = { 1, 0, -1, 0 };
void BFS(int** map, int** check);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	int** map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
	}
	int** check = new int* [N];
	for (int i = 0; i < N; i++) {
		check[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			check[i][j] = -1;
		}
	}

	BFS(map, check);
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				max = -1;
				break;
			}
			if (check[i][j] > max) {
				max = check[i][j];
			}
		}
		if (max == -1) {
			break;
		}
	}
	cout << max << "\n";
}
void BFS(int** map, int** check) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int mx = dx[k] + x;
			int my = dy[k] + y;
			if (mx < 0 || my < 0 || mx >= N || my >= M)
				continue;
			if (check[mx][my] != -1 || map[mx][my] == -1 || map[mx][my] == 1)
				continue;
			map[mx][my] = 1;
			check[mx][my] = check[x][y] + 1;
			q.push(make_pair(mx, my));
		}
	}
}