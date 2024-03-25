#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, a[100004], ret = 1e18;

bool check(ll mid) {
    ll res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] > mid) {
            sum = 0;
            res++;
        }
        sum += a[i];
    }
    return res + 1 <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    ll lo = 0, hi = 0, mid;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; lo = max(lo, a[i]); hi += a[i];
    }
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ret << '\n';
}