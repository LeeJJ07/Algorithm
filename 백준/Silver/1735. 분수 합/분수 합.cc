#include <iostream>
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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int e = a * d + b * c;
	int f = b * d;
	int g = gcd(e, f);
	cout << e/g << ' ' << f/g;
}