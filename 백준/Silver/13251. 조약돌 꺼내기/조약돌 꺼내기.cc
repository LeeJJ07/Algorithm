#include <iostream>
using namespace std;

static int M, K, T;
static int D[51];
static double probability[51];
static double ans = 0.0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> D[i];
		T += D[i];
	}
	cin >> K;

	for (int i = 0; i < M; i++) {
		if (D[i] >= K) {
			probability[i] = 1.0;

			for (int k = 0; k < K; k++) {
				probability[i] *= (double)(D[i] - k) / (T - k);
			}
		}
		ans += probability[i];
	}
	cout << fixed;
	cout.precision(9);
	cout << ans;
}