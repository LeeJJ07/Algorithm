#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, i; cin >> n >> k;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			k--;
		}
		if (k == 0) { cout << i; break; }
	}
	if (i == n + 1) cout << 0 << '\n';
}