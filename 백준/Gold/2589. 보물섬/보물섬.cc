#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<vector<int>> m;
int result = 0;

void BFS(int y, int x) {
	vector<vector<int>> visited(N);
	for (int i = 0; i < N; i++) visited[i].resize(M);
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (q.size()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] || m[ny][nx]) continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[now.first][now.second] + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = max(result, visited[i][j] - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	m.resize(N);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m[i].resize(M);
		for (int j = 0; j < M; j++) {
			if (str[j] == 'L') {
				m[i][j] = 0;
			}
			else if (str[j] == 'W') {
				m[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(m[i][j]==0) BFS(i, j);
		}
	}
	cout << result << '\n';
}