#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> day(N + 1, 0);
	vector<int> sum(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> day[i];
	}
	sum[1] = day[1];
	for (int i = 2; i <= N; i++) {
		sum[i] = sum[i - 1] + day[i];
	}
	int s = 0;
	int e = K;
	int max = INT_MIN;
	while (e <= N) {
		if (sum[e] - sum[s] > max) {
			max = sum[e] - sum[s];
		}
		e++, s++;
	}
	cout << max << '\n';
}