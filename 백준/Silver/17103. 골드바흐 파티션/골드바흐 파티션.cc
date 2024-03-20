#include <iostream>
using namespace std;
int num[1000004];

int sosu(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			num[n] = -1;
			return false;
		}
	}
	num[n] = 1;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, s, e, ret; cin >> T;
	while (T--) {
		cin >> n;
		s = 2; e = n - s;
		ret = 0;
		while (s <= e) {
			if (num[s] == 1 && num[e] == 1) ret++;
			else {
				if (num[s] == 0) sosu(s);
				if (num[e] == 0) sosu(e);
				if (num[s] == 1 && num[e] == 1) ret++;
			}
			s++; e--;
		}
		cout << ret << '\n';
	}
}