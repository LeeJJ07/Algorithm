#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 101;
int N;
int m[MAX_N][MAX_N];
int maxLevel = 0;
int maxResult = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 };

void go(int y, int x, vector<vector<int>>& check, vector<vector<int>>& visited) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (visited[ny][nx] != 0 || check[ny][nx] == 0)
			continue;
		go(ny, nx, check, visited);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			maxLevel = max(maxLevel, m[i][j]);
		}
	}
	for (int i = 0; i <= maxLevel; i++) {
		vector<vector<int>> check(N);
		vector<vector<int>> visited(N);
		for (int j = 0; j < N; j++) {
			visited[j].resize(N, 0);
			check[j].resize(N, 0);
			for (int k = 0; k < N; k++) {
				if (m[j][k] <= i)
					check[j][k] = 0;
				else
					check[j][k] = 1;
			}
		}
		int result = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (check[y][x] == 0 || visited[y][x] != 0)
					continue;
				result++;
				go(y, x, check, visited);
			}
		}
		maxResult = max(maxResult, result);
	}
	cout << maxResult << '\n';
}