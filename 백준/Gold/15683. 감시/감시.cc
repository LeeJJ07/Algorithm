#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 100;
vector<pair<pair<int, int>, int>> cctv;
int room[8][8];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void pm_cctv(int y, int x, int d, int num) {
	int ny = y, nx = x;
	while (true) {
		ny += dy[d];
		nx += dx[d];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || room[ny][nx] == 6) break;
		if (room[ny][nx] <= 0) {
			room[ny][nx] += num;
		}
	}
}

void dfs(int depth) {
	if (depth == cctv.size()) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (room[i][j]) continue;
				res++;
			}
		}
		result = min(result, res);
		return;
	}
	int y = cctv[depth].first.first, x = cctv[depth].first.second;
	int kind = cctv[depth].second;
	if (kind == 1) {
		for (int i = 0; i < 4; i++) {
			pm_cctv(y, x, i, -1);
			dfs(depth + 1);
			pm_cctv(y, x, i , 1);
		}
	}
	else if (kind == 2) {
		for (int i = 0; i < 2; i++) {
			pm_cctv(y, x, i, -1);
			pm_cctv(y, x, i + 2, -1);
			dfs(depth + 1);
			pm_cctv(y, x, i, 1);
			pm_cctv(y, x, i + 2, 1);
		}
	}
	else if (kind == 3) {
		for (int i = 0; i < 4; i++) {
			pm_cctv(y, x, i, -1);
			pm_cctv(y, x, (i + 1) % 4, -1);
			dfs(depth + 1);
			pm_cctv(y, x, i, 1);
			pm_cctv(y, x, (i + 1) % 4, 1);
		}
	}
	else if (kind == 4) {
		for (int i = 0; i < 4; i++) pm_cctv(y, x, i, -1);
		for (int i = 0; i < 4; i++) {
			pm_cctv(y, x, i, 1);
			dfs(depth + 1);
			pm_cctv(y, x, i, -1);
		}
		for (int i = 0; i < 4; i++) pm_cctv(y, x, i, 1);
	}
	else if (kind == 5) {
		for (int i = 0; i < 4; i++) pm_cctv(y, x, i, -1);
		dfs(depth + 1);
		for (int i = 0; i < 4; i++) pm_cctv(y, x, i, 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] > 0 && room[i][j] < 6) 
				cctv.push_back({ {i, j}, room[i][j] });
		}
	}
	dfs(0);
	cout << result << '\n';
}