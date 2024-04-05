#include <iostream>
using namespace std;
int n, c[5004];
double m, p[5004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n >> m; if (n == 0 && m == 0.0) break;
		int mm = 100 * m;
		int dp[10004] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> c[i] >> p[i];
		}
		for (int i = 0; i < n; i++) {
			int idx = (int)(100 * p[i] + 0.5);
			for (int j = idx; j <= mm; j++) {
				dp[j] = max(dp[j], dp[j - idx] + c[i]);
			}
		}
		cout << dp[mm] << '\n';
	}
}