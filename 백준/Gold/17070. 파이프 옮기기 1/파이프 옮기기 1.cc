#include <iostream>
using namespace std;
int n, res;
int m[17][17];
int dy[3][3] = { { 0, 1 }, { 1, 1 }, { 0, 1, 1} };
int dx[3][3] = { { 1, 1 }, { 0, 1 }, {1, 1, 0} };

void dfs(int y, int x, int i) {
    if (y == n - 1 && x == n - 1) {
        res++; return;
    }
    for (int j = 0; j < 3; j++) {
        if ((i == 0 || i == 1) && (j == 2)) continue;
        int ny = dy[i][j] + y;
        int nx = dx[i][j] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (m[ny][nx]) continue;
        if (j == 1 && (m[ny - 1][nx] == 1 || m[ny][nx - 1] == 1))continue;
        if (j == 1) dfs(ny, nx, 2);
        else if ((i == 0 || i == 2) && j == 0) dfs(ny, nx, 0);
        else if (i == 1 && j == 0) dfs(ny, nx, 1);
        else if (i == 2 && j == 2) dfs(ny, nx, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    dfs(0, 1, 0);
    cout << res << '\n';
}