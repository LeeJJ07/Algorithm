#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, m, k, r, c, s;
int a[54][54];
int temp[54][54];

void _turn_all(int y, int x, int sz) {
	int ny = y, nx = x;
	int idx = 0;
	vector<int> tmp((sz - 1) * 4);
	for (int i = 0; i < 4; i++) {
		while (idx<tmp.size() && ny >= y && nx >= x && ny <= y + sz - 1 && nx <= x + sz - 1) {
			tmp[idx++] = temp[ny][nx];
			ny += dy[i];
			nx += dx[i];
		}
		ny -= dy[i];
		nx -= dx[i];
		idx--;
	}
	int tp = tmp[tmp.size() - 1];
	for (int i = tmp.size()-1; i >0; i--) tmp[i] = tmp[i - 1];
	tmp[0] = tp;
	ny = y, nx = x;
	idx = 0;
	for (int i = 0; i < 4; i++) {
		while (idx < tmp.size() && ny >= y && nx >= x && ny <= y + sz - 1 && nx <= x + sz - 1) {
			temp[ny][nx] = tmp[idx++];
			ny += dy[i];
			nx += dx[i];
		}
		ny -= dy[i];
		nx -= dx[i];
		idx--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> v;
	vector<tuple<int, int, int>> vv;
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		vv.push_back({r, c, s});
		v.push_back(i);
	}
	int res = 98765432;
	do {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			s = get<2>(vv[v[i]]);
			c = get<1>(vv[v[i]]);
			r = get<0>(vv[v[i]]);
			int sz = 2 * s + 1, sy = r - s, sx = c - s;
			while (sz > 1) {
				_turn_all(sy, sx, sz);
				sy++; sx++;
				sz -= 2;
			}
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += temp[i][j];
			}
			res = min(res, sum);
		}
	} while (next_permutation(v.begin(), v.end()));
	
	cout << res << '\n';
}