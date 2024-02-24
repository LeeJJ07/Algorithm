#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<vector<int>> A;
vector<vector<int>> visited;
void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 1;

	while (q.size()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = now.first + dx[i];
			int my = now.second + dy[i];
			
			if (mx < 0 || my < 0 || mx >= N || my >= M)
				continue;
			if (visited[mx][my] != -1 || A[mx][my]==0)
				continue;
			visited[mx][my] = visited[now.first][now.second] + 1;
			q.push(make_pair(mx, my));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++) {
		A[i].resize(M);
		visited[i].resize(M, -1);
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			A[i][j] = input[j] - '0';
		}
	}
	BFS(0, 0);

	cout << visited[N - 1][M - 1] << '\n';
}