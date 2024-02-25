#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int Count;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> m;
vector<vector<bool>> visited;
vector<int> result;

void go(int y, int x) {
	visited[y][x] = true;
	Count++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
		if (visited[ny][nx] || m[ny][nx])continue;
		go(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	m.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		visited[i].resize(M);
	}
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				m[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]||m[i][j]) continue;
			Count = 0;
			go(i, j);
			result.push_back(Count);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int res : result) cout << res << ' ';
}