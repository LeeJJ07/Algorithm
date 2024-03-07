#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, K;
	cin >> N >> K;
	long s = 1, e = K;
	long ans = 0;

	while (s <= e) {
		long m = (s + e) / 2;
		long cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(m / i, N);
		}
		if (cnt < K) {
			s = m + 1;
		}
		else {
			ans = m;
			e = m - 1;
		}
	}
	cout << ans << "\n";
}