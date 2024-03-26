#include <iostream>
using namespace std;

int n, num;
int dp[304][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0) { dp[i][0] = 0; dp[i][1] = num; }
		else if (i == 1) { dp[i][0] = num; dp[i][1] = dp[i-1][1] + num; }
		else {
			int mx = max(dp[i - 2][0], dp[i - 2][1]);
			dp[i][0] = mx + num;
			dp[i][1] = dp[i - 1][0] + num;
		}
	}
	cout << max(dp[n-1][0],dp[n-1][1]) << '\n';
}