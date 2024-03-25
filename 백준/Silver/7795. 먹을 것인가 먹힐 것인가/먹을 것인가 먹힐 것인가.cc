#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll t, n, m, a[20004], b[20004], result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        result = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        ll lo = 0, hi = m - 1, mid;
        for (int i = n - 1; i >= 0; i--) {
            ll ret = -1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (a[i] > b[mid]) {
                    ret = max(ret, mid);
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            result += ret + 1;
            lo = 0; hi = ret;
        }
        cout << result << '\n';
    }
}