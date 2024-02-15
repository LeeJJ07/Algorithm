#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
typedef pair<int, int> pos;
vector<vector<char>> map;
vector<vector<bool>> visited;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int result = 0;

void BFS(pos s) {
	queue<pos> q;
	q.push(s);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = now.first + dx[i];
			int my = now.second + dy[i];
			if (mx < 0 || my < 0 || mx >= N || my >= M)
				continue;
			if (visited[mx][my])
				continue;
			if (map[mx][my] == 'X')
				continue;
			if (map[mx][my] == 'P') {
				result++;
			}
			q.push(make_pair(mx, my));
			visited[mx][my] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	map.resize(N);
	visited.resize(N);

	pos start;
	
	for (int i = 0; i < N; i++) {
		visited[i].resize(M, false);
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;
			map[i].push_back(a);
			if (a == 'I') {
				start = { i, j };
				visited[i][j] = true;
			}
		}
	}

	BFS(start);
	if (result == 0) {
		cout << "TT" << '\n';
	}
	else {
		cout << result << '\n';
	}
}