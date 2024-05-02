#include <iostream>
#include <vector>
using namespace std;
typedef long double ld;
int n, m[10004][2];
ld res;

ld go(int i, int j) {
	ld a = m[0][0], b = m[0][1];
	ld c = m[i][0], d = m[i][1];
	ld e = m[j][0], f = m[j][1];

	return (a * d + c * f + e * b - b * c - d * e - f * a) / 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i][0] >> m[i][1];
	for (int i = 1; i < n - 1; i++) {
		res += go(i, i + 1);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(res) << endl;
}