#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int a[101][101];
int n, x, y, d, g;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;
		vector<pair<int, int>> v;
		int nx = dx[d] + x;
		int ny = dy[d] + y;
		v.push_back({ x, y });
		v.push_back({ nx, ny });
		while (g--) {
			int std_x = v.back().first, std_y = v.back().second;
			for (int i = v.size() - 2; i >= 0; i--) {
				v.push_back({ std_x + std_y - v[i].second , -std_x + std_y + v[i].first });
			}
		}
		for (pair<int, int> point : v) {
			if (point.first < 0 || point.second < 0 || point.first>100 || point.second>100)continue;
			a[point.first][point.second] = 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1)
				ret++;
		}
	}
	cout << ret << '\n';
}