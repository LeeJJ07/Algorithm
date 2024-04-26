#include <iostream>
using namespace std;
int t, m, n, x, y, result, maxi;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		result = -1;
		maxi = lcm(m, n);
		for (int i = x; i <= maxi; i += m) {
			int ny = i % n;
			if (!ny) ny = n;
			if (ny == y) {
				result = i;
				break;
			}
		}
		cout << result << '\n';
	}
}