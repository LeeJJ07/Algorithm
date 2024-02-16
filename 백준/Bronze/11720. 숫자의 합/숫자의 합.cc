#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		sum += int(c - '0');
	}
	cout << sum << '\n';
}