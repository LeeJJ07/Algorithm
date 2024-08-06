#include <iostream>
#include <queue>
using namespace std;

int N, M;
int mp[504][504];
int check[504][504];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1 ,0 };

int bfs(int y, int x)
{
	int res = 1;

	queue<pair<int, int>> q;
	q.push({ y, x });
	check[y][x] = 1;

	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (check[ny][nx]||!mp[ny][nx]) continue;
			q.push({ ny, nx });
			check[ny][nx] = 1;
			res++;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> mp[i][j];

	int _count = 0;
	int _max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!mp[i][j] || check[i][j])
				continue;
			_max = max(_max, bfs(i, j));
			_count++;
		}
	}
	cout << _count << "\n" << _max << "\n";
}