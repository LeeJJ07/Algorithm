#include <iostream>
const int INF = 987654321;
using namespace std;
int n, m, ii, jj, vv;
int a[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	fill(&a[1][1], &a[n][n + 1], INF);
	for (int i = 0; i < m; i++) {
		cin >> ii >> jj >> vv;
		a[ii][jj] = min(a[ii][jj], vv);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) a[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == INF) a[i][j] = 0;
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}