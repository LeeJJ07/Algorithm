#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int row = 12;
const int col = 6;

int m[row][col];
int visited[row][col];
vector<pair<int, int>>chk;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool bfs(int y, int x, int num)
{
    int res = 0;
    queue<pair<int, int>> q;
    q.push({ y, x });
    chk.push_back({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        res++;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
            if (visited[ny][nx] || m[ny][nx] != num) continue;
            
            visited[ny][nx] = 1;
            chk.push_back({ ny,nx });
            q.push({ ny, nx });
        }
    }
    if (res >= 4)
    {
        for (pair<int, int> i : chk)
            visited[i.first][i.second] = 2;
    }
    return res >= 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < row; i++)
    {
        string input; cin >> input;
        for (int j = 0; j < col; j++)
        {
            if (input[j] == '.') continue;
            m[i][j] = input[j] - 'A' + 1;
        }
    }
    
    int res = -1;
    bool notFinish = true;

    while (notFinish)
    {
        notFinish = false;
        res++;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!m[i][j] || visited[i][j]) continue;
                if (notFinish)
                    bfs(i, j, m[i][j]);
                else
                    notFinish = bfs(i, j, m[i][j]);
                chk.clear();
            }
        }

        for (int j = 0; j < col; j++)
        {
            int boomCount = 0;
            for (int i = row - 1; i >= 0; i--)
            {
                if (visited[i][j] == 2) { boomCount++; continue; }
                m[i + boomCount][j] = m[i][j];
            }
            for (int i = 0; i < boomCount; i++)
                m[i][j] = 0;
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << res << '\n';

    return 0;
}