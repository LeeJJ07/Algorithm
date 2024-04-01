#include <iostream>
using namespace std;
int n;
long long dp[41];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    dp[5] = 5; dp[6] = 8;
    for (int i = 7; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[n] << " " << n - 2 << '\n';
}