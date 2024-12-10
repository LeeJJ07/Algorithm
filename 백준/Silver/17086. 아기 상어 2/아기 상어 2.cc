#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int m[54][54], visited[54][54];
queue<pair<int, int>> sharks;

int mx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int my[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

int bfs() {
    
    while (sharks.size()) {
        pair<int, int> now = sharks.front();
        sharks.pop();

        for (int i = 0; i < 8; i++) {
            int ny = my[i] + now.first;
            int nx = mx[i] + now.second;
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || !visited[ny][nx])
                continue;
            if (visited[ny][nx] == -1) {
                visited[ny][nx] = visited[now.first][now.second] + 1;
                sharks.push({ ny, nx });
            }
            else if (visited[ny][nx] > visited[now.first][now.second] + 1) {
                visited[ny][nx] = visited[now.first][now.second] + 1;
                sharks.push({ ny, nx });
            }
        }
    }

    int result = -1;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if (visited[i][j] > result)
                result = visited[i][j];
        }
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(visited, -1, sizeof(visited));

    cin >> N >> M;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> m[i][j];
            if (!m[i][j])
                continue;
            sharks.push({ i,j });
            visited[i][j] = 0;
        }
    }

    cout << bfs();

    return 0;
}