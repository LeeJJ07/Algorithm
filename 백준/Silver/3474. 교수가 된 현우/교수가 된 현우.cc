#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		long num;
		cin >> num;
		long result = 0;
		while (num > 0) {
			result += num / 5;
			num /= 5;
		}
		cout << result << '\n';
	}
}