#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, resA, resB, resC, a[5004];
ll ret = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int m = 1; m < n - 1; m++) {
		ll s = m + 1;
		ll e = n;
		while (s < e) {
			ll v = a[m] + a[s] + a[e];
			if (abs(v) < ret) {
				ret = abs(v);
				resA = a[m];
				resB = a[s];
				resC = a[e];
			}
			if (v < 0) s++;
			else e--;
		}
	}
	cout << resA << ' ' << resB << ' ' << resC;
}