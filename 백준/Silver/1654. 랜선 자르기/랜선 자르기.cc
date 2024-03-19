#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K, N;
	cin >> K >> N;
	long long res = 0;
	vector<long long>v(K);
	long long maxV = 0;
	for (int i = 0; i < K; i++) {
		cin >> v[i];
		maxV = max(maxV, v[i]);
	}
	long long int l = 1, r = maxV, m;

	while (l <= r) {
		m = (l + r) / 2;
		long long now = 0;
		for (int i = 0; i < K; i++) now += v[i] / m;
		if (now >= N) { l = m + 1; res = max(res, m); }
		else r = m - 1;
	}
	cout << res << '\n';
}