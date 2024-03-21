#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> yx;
int n, k, l, apy, apx, tm;
char c;
int a[104][104];
vector<pair<int, char>> v;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> apy >> apx;
		a[apy][apx] = -1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> tm >> c;
		v.push_back({ tm,c });
	}
	int hy = 1, hx = 1;
	queue<yx> q;
	q.push({ hy, hx });
	a[hy][hx] = 1;
	int idx = 0;
	int t = 0;
	bool find = false;
	for (pair<int, char> next : v) {
		while (next.first > t) {
			int ny = q.back().first + dy[idx];
			int nx = q.back().second + dx[idx];
			if (ny <= 0 || nx <= 0 || ny > n || nx > n || a[ny][nx] == 1) {
				find = true; break;
			}
			else if (a[ny][nx] == -1) {
				a[ny][nx] = 1;
				q.push({ ny,nx });
			}
			else if(a[ny][nx] == 0) {
				a[ny][nx] = 1;
				int yy = q.front().first, xx = q.front().second;
				a[yy][xx] = 0;
				q.pop();
				q.push({ ny,nx });
			}
			t++;
		}
		if (find) break;
		if (next.second == 'D') {
			idx++;
			if (idx == 4) idx = 0;
		}
		else if(next.second == 'L'){
			idx--;
			if (idx == -1) idx = 3;
		}
	}
	if (!find) {
		int ny = q.back().first;
		int nx = q.back().second;
		while (true) {
			ny += dy[idx];
			nx += dx[idx];
			if (ny <= 0 || nx <= 0 || ny > n || nx > n || a[ny][nx] == 1) {
				break;
			}
			t++;
		}
	}
	cout << t + 1 << '\n';
}