#include <iostream>
using namespace std;
int n, m;
int a[51][51], visited[51][51], d[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool in(int aa, int bb) {
    return (0 <= aa && aa < n && 0 <= bb && bb < m);
}
int dfs(int y, int x) {
    if (!in(y, x) || a[y][x] == -1) return 0;
    if (visited[y][x]) {
        cout << -1 << '\n';
        exit(0);
    }
    int& ret = d[y][x];
    if (ret) return ret;
    visited[y][x] = 1;
    int value = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, dfs(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == 'H') a[i][j] = -1;
            else a[i][j] = str[j] - '0';
        }
    }
    cout << dfs(0, 0) << '\n';
}