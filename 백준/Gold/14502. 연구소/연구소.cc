#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> node;
vector<vector<int>> m;

int N, M;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int BFS() {
	queue<node> q;
	vector<vector<bool>> visited(N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		visited[i].resize(M);
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 2) {
				q.push({ i,j });
			}
			if (m[i][j] != 0)
				visited[i][j] = true;
		}
	}
	while (q.size()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= M)continue;
			if (visited[ny][nx]) continue;
			if (m[ny][nx] == 0) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j])continue;
			count++;
		}
	}
	return count;
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
	int result = 0;
	for (int i = 0; i < N * M; i++) {
		if (m[i / M][i % M] == 0) {
			m[i / M][i % M] = 1;
			for (int j = i+1; j < N * M; j++) {
				if (m[j / M][j % M] == 0) {
					m[j / M][j % M] = 1;
					for (int k = j+1; k < N * M; k++) {
						if (m[k / M][k % M] == 0) {
							m[k / M][k % M] = 1;
							result = max(result, BFS());
							m[k / M][k % M] = 0;
						}
					}
					m[j / M][j % M] = 0;
				}
			}
			m[i / M][i % M] = 0;
		}
	}
	cout << result << '\n';
}