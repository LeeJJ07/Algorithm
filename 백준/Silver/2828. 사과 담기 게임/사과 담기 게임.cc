#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int s = 1, e = M;
	int result = 0;
	for (int i = 0; i < K; i++) {
		int pos;
		cin >> pos;
		if (pos >= s && pos <= e) continue;
		else if (pos < s) {
			result += s - pos;
			e -= s - pos;
			s = pos;
		}
		else if (pos > e) {
			result += pos - e;
			s += pos - e;
			e = pos;
		}
	}
	cout << result << '\n';
}