#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll s, c, num, sum, ret;
vector<ll> a;

bool check(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < s; i++) cnt += a[i] / mid;
	return cnt >= c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> num; sum += num;
		a.push_back(num);
	}
	ll lo = 1, hi = 1e9, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			ret = mid;
		}
		else hi = mid - 1;
	}
	cout << sum - ret * c << '\n';
}