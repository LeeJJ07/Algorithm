#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef tuple<int, int, int> tp;
int M, N, H;
int result;
vector<vector<vector<int>>> m;
vector<vector<vector<int>>> visited;

int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 1, 0, -1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };

void BFS() {
	queue<tp> q;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[h][i][j] == 1) {
					q.push({ h,i,j });
					visited[h][i][j] = 1;
				}
				else if (m[h][i][j] == -1) {
					visited[h][i][j] = -1;
				}
			}
		}
	}

	while (q.size()) {
		tp now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = get<0>(now) + dz[i];
			int ny = get<1>(now) + dy[i];
			int nx = get<2>(now) + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
			if (visited[nz][ny][nx] != 0 || m[nz][ny][nx] == -1) continue;
			q.push({ nz,ny,nx });
			visited[nz][ny][nx] = visited[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
		}
	}
}

bool check() {
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[h][i][j] == 0) return false;
				result = max(result, visited[h][i][j]);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N >> H;
	m.resize(H);
	visited.resize(H);
	for (int h = 0; h < H; h++) {
		m[h].resize(N);
		visited[h].resize(N);
		for (int i = 0; i < N; i++) {
			m[h][i].resize(M);
			visited[h][i].resize(M, 0);
			for (int j = 0; j < M; j++) {
				cin >> m[h][i][j];
			}
		}
	}
	BFS();
	if (check()) cout << result - 1 << '\n';
	else cout << -1 << '\n';
}