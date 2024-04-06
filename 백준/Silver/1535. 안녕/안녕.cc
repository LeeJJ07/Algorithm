#include <iostream>
using namespace std;
int n, dp[24][104], h[24], p[24];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j > h[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + p[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][100] << '\n';
}