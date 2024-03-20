#include <iostream>
using namespace std;
typedef long long ll;

int sosu(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T; ll n;
	while (T--) {
		cin >> n;
		if (n == 0 || n == 1) {
			cout << 2 << '\n';
			continue;
		}
		while (!sosu(n)) n++;
		cout << n << '\n';
	}
}