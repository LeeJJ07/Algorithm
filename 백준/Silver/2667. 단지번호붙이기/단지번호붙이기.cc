#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, level;
int a[26][26], visited[26][26];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
    visited[y][x] = level;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < n; j++) {
            a[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j] || visited[i][j]) continue;
            level++;
            dfs(i, j);
        }
    }
    vector<int> result(level);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) continue;
            result[visited[i][j] - 1]++;
        }
    }
    sort(result.begin(), result.end());
    cout << level << '\n';
    for (int num : result) cout << num << '\n';
}