#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int result = 0;
	for (int i = 5; i <= N; i++) {
		int n = 5;
		while (i % n == 0) {
			result++;
			n *= 5;
		}
	}
	cout << result << '\n';
}