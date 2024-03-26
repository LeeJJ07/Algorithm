#include <iostream>
using namespace std;
typedef long long ll;
ll x, y;

bool check(ll mid) {
	ll z = y * 100 / x;
	ll zz = (y + mid) * 100 / (x + mid);
	return z != zz;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;
	ll lo = 1, hi = 1e10, mid, res = 1e18;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			res = min(res, mid);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	if (res == 1e18) cout << -1 << '\n';
	else cout << res << '\n';
}