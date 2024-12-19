#include <iostream>
#include <vector>
using namespace std;

int N;
string input;
vector<string> str;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

pair<int, int> Heart()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (str[i][j] == '-') continue;
			int k;
			for (k = 0; k < 4; k++)
			{
				int nx = dx[k] + j;
				int ny = dy[k] + i;
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
				if (str[ny][nx] == '_') break;
			}
			if (k == 4)
				return { i, j };
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		str.push_back(input);
	}

	pair<int, int> heart = Heart();
	vector<int> result;
	cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
	for (int i = 1; i < 4; i++)
	{
		int ny = heart.first, nx = heart.second;
		int res = -1;
		while (ny >= 0 && nx >= 0 && ny < N && nx < N && str[ny][nx] == '*')
		{
			res++;
			ny += dy[i];
			nx += dx[i];
		}
		result.push_back(res);
		if (i == 3)
		{
			int leg[2] = { nx - 1, nx + 1 };
			for (int j = 0; j < 2; j++)
			{
				res = 0;
				int legY = ny;
				while (legY >= 0 && leg[j] >= 0 && legY < N && leg[j] < N && str[legY][leg[j]] == '*')
				{
					res++;
					legY += dy[i];
				}
				result.push_back(res);
			}
		}
	}

	for (int output : result)
		cout << output << ' ';

	return 0;
}