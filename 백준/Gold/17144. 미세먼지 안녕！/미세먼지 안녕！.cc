#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> node;

int r, c, t;
int a[54][54];
vector<node>start;
vector<pair<node, int>> dust;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void turn() {
	for (int i = start[0].first; i > 0; i--) a[i][0] = a[i - 1][0];
	for (int j = 1; j < c; j++) a[0][j - 1] = a[0][j];
	for (int i = 0; i < start[0].first; i++) a[i][c - 1] = a[i + 1][c - 1];
	for (int j = c - 1; j > 0; j--) a[start[0].first][j] = a[start[0].first][j - 1];
	a[start[0].first][start[0].second] = -1;
	a[start[0].first][start[0].second+1] = 0;
	for (int i = start[1].first + 1; i < r; i++) a[i-1][0] = a[i][0];
	for (int j = 1; j < c; j++) a[r - 1][j - 1] = a[r - 1][j];
	for (int i = r - 1; i > start[1].first; i--) a[i][c - 1] = a[i - 1][c - 1];
	for (int j = c - 1; j > 0; j--) a[start[1].first][j] = a[start[1].first][j - 1];
	a[start[1].first][start[1].second] = -1;
	a[start[1].first][start[1].second + 1] = 0;
}

void bfs() {
	queue<pair<node, int>> q;
	for (pair<node, int> d : dust) q.push(d);
	while (t--) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pair<node, int> now = q.front();
			q.pop();
			if (now.second < 5)continue;
			int plus = now.second / 5;
			for (int j = 0; j < 4; j++) {
				int ny = now.first.first + dy[j];
				int nx = now.first.second + dx[j];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1)continue;
				a[ny][nx] += plus;
				a[now.first.first][now.first.second] -= plus;
			}
		}
		turn();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0)q.push({ {i,j},a[i][j] });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) start.push_back({ i,j });
			else if (a[i][j]) dust.push_back({ {i,j},a[i][j] });
		}
	}
	bfs();
	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) res += a[i][j];
		}
	}
	cout << res << '\n';
}