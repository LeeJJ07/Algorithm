#include <iostream>
using namespace std;
typedef long long ll;
ll n, dp[31][31];
ll go(int W, int H) {
    if (W == 0 && H == 0) return 1;
    if (dp[W][H]) return dp[W][H];
    ll& ret = dp[W][H];
    if (W > 0) ret += go(W - 1, H + 1);
    if (H > 0) ret += go(W, H - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> n; if (n == 0) break;
        cout << go(n, 0) << '\n';
    }
}