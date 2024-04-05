#include <iostream>
using namespace std;
int n, k, dp[10004], temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			dp[j] += dp[j - temp];
		}
	}
	cout << dp[k] << '\n';
}