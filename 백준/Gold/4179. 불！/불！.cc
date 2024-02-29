#include <iostream>
#include <queue>

using namespace std;

int r, c;
char a[1004][1004];
int visited[1004][1004];
int mvisited[1004][1004];
vector<pair<int, int>> v;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void BFS() {
	queue<pair<int, int>> q;
	for (pair<int, int> i : v) q.push(i);

	while (q.size()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx])continue;
			if (a[ny][nx] == '#') continue;
			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny, nx });
		}
	}
}

int MBFS(pair<int, int> s) {
	queue<pair<int, int>>q;
	q.push(s);
	
	while (q.size()) {
		pair<int, int> now = q.front();
		q.pop();
		if (now.first == 0 || now.second == 0 || now.first == r - 1 || now.second == c - 1)
			return mvisited[now.first][now.second];
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || mvisited[ny][nx]) continue;
			if (a[ny][nx] == '#') continue;
			if (visited[ny][nx]!=0 && visited[ny][nx] <= mvisited[now.first][now.second] + 1) continue;
			mvisited[ny][nx] = mvisited[now.first][now.second] + 1;
			q.push({ ny, nx });
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	pair<int, int> s;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				v.push_back({ i,j });
				visited[i][j] = 1;
			}
			else if (a[i][j] == 'J') {
				s = { i,j };
				mvisited[i][j] = 1;
			}
		}
	}
	BFS();
	int res = MBFS(s);
	if (res == 0) cout << "IMPOSSIBLE" << '\n';
	else cout << res << '\n';
	return 0;
}