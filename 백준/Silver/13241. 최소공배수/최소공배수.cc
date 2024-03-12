#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int a, b, i;
	cin >> a >> b;
	long long int mx = max(a, b);
	for (i = mx;; i += mx) {
		if (i % a == 0 && i % b == 0)break;
	}
	cout << i << '\n';
}