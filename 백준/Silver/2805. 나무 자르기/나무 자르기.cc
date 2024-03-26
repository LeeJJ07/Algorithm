#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> a;
bool check(ll mid) {
	ll sum = 0;
	for (int i = n - 1; i>=0 && a[i] > mid; i--) {
		sum += a[i] - mid;
	}
	return sum >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> k; a.push_back(k);
		mx = max(mx, a[i]);
	}
	sort(a.begin(), a.end());
	ll s = 0, e = mx, mid, res = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (check(mid)) {
			res = max(res, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << res << '\n';
}