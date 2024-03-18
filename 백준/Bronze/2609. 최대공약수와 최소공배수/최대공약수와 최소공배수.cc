#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b; cin >> a >> b;
	int mx = max(a, b);
	int mn = min(a, b);
	for (int i = mn; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << '\n'; break;
		}
	}
	for (int i = mx;; i += mx) {
		if (i % a == 0 && i % b == 0) {
			cout << i << '\n'; break;
		}
	}
}