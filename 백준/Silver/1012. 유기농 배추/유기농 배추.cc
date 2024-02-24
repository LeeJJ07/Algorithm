#include <iostream>
#include <vector>
using namespace std;

int M, N, K;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void go(int y, int x, vector<vector<int>>& m, vector<vector<int>>& visited) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (visited[ny][nx] != 0 || m[ny][nx] == 0)
			continue;
		go(ny, nx, m, visited);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		vector<vector<int>> m(N);
		vector<vector<int>> visited(N);
		for (int j = 0; j < N; j++) {
			m[j].resize(M);
			visited[j].resize(M);
		}
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			m[y][x] = 1;
		}
		int level = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (m[j][k] == 0 || visited[j][k] != 0)
					continue;
				level++;
				go(j, k, m, visited);
			}
		}
		cout << level << '\n';
	}
}