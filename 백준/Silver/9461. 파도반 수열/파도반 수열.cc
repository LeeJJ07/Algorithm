#include <iostream>
using namespace std;

long long t, n;
long long dp[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for (int i = 4; i <= 100; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}