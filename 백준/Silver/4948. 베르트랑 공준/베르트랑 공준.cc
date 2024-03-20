#include <iostream>
using namespace std;

int sosu(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, res;
	while (true) {
		cin >> n;
		if (n == 0) break;
		res = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (sosu(i)) res++;
		}
		cout << res << '\n';
	}
}