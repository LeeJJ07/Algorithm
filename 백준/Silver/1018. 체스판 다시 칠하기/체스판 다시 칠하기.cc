#include <iostream>
using namespace std;

char a[54][54];
int result = 100;
int n, m;
int chk(int y, int x) {
	int res1 = 0, res2 = 0;
	char c[] = { 'W', 'B' };
	for (int i = 0; i < 8; i++) {
		int start = i % 2;
		for (int j = 0; j < 8; j++) {
			if (c[start % 2] == a[i + y][j + x])res1++;
			else res2++;
			start++;
		}
	}
	return min(res1, res2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			result = min(result, chk(i, j));
		}
	}
	cout << result << '\n';
}