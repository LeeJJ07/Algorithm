#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	vector<int> diff(n - 1);
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 1; i < n; i++) {
		diff[i - 1] = v[i] - v[i - 1];
	}
	sort(diff.begin(), diff.end());
	int mn = diff[0];
	for (int i = 1; i < n - 1; i++) {
		if (diff[i] % mn == 0)continue;
		mn = gcd(mn, diff[i]);
	}
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		res += diff[i] / mn - 1;
	}
	cout << res << '\n';
}