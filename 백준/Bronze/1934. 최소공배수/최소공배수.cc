#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, j;
		cin >> a >> b;
		int sum = max(a, b);
		for (j = sum;; j+=sum) {
			if (j % a == 0 && j % b == 0) break;
		}
		cout << j << '\n';
	}
}