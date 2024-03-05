#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define y1 aaaa

int n, m, x1, y1, x2, y2;
char mp[304][304];
int visited[304][304];
vector<pair<int, int>> a;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool BFS() {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ y1, x1 });
	visited[y1][x1] = 1;
	while (q.size()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx]) continue;
			if (mp[ny][nx]=='1') {
				a.push_back({ ny,nx });
				continue;
			}
			if (mp[ny][nx] == '#') return true;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	for (pair<int, int> i : a) {
		mp[i.first][i.second] = '0';
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}
	int result = 0;
	while (!BFS()) {
		result++;
	}
	cout << result + 1 << '\n';
	return 0;
}