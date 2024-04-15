#include <iostream>
using namespace std;
#define MAX 1000000
int n, dp[1001][3], color[1001][3], ans = MAX;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	
	for (int rgb = 0; rgb <= 2; rgb++) {
		for(int i = 0; i <= 2; i++) {
			if (i == rgb) dp[1][i] = color[1][i];
			else dp[1][i] = MAX;
		}

		for (int i = 2; i <= n; i++) {
			dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i <= 2; i++) {
			if (i == rgb)continue;
			else ans = min(ans, dp[n][i]);
		}
	}
	cout << ans;
}