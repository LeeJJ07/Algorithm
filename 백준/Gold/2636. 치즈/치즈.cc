#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> m;
int visited[101][101];
int check[101][101];

int N, M;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
		if (visited[ny][nx])continue;
		if (m[ny][nx] == 1) {
			check[ny][nx] = 1;
			continue;
		}
		DFS(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	int count = 0;
	int prev = 0;
	int result = 0;
	while (true) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		fill(&check[0][0], &check[0][0] + 101 * 101, 0);
		DFS(0, 0);
		prev = count;
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 1) {
					m[i][j] = 0;
					count++;
				}
			}
		}
		if (count == 0) break;
		result++;
	}
	cout << result << '\n';
	cout << prev << '\n';
}