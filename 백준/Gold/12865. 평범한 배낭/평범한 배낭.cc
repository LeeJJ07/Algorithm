#include <iostream>
using namespace std;
int dp[100001];
int n, k, w, v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	while (n--) {
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k] << '\n';
}