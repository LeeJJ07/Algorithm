#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> node;
int n, m;
int a[1004][1004];
int visited[1004][1004];
node s;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs() {
    queue<node> q;
    q.push(s);
    visited[s.first][s.second] = 1;
    while (q.size()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + now.first;
            int nx = dx[i] + now.second;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]||!a[ny][nx]) continue;
            visited[ny][nx] = visited[now.first][now.second] + 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                s.first = i, s.second = j;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) cout << visited[i][j] - 1 << ' ';
            else if (!a[i][j]) cout << 0 << ' ';
            else cout << -1 << ' ';
        }
        cout << '\n';
    }
}