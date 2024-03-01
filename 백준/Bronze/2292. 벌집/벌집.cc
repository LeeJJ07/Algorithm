#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int minus = 1;
	int result = 0;
	while (N > 0) {
		N -= minus;
		result++;
		minus = result * 6;
	}
	cout << result << '\n';
}