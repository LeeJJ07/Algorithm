#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;
	long long num = pow(2, N) * pow(2, N);
	long long div = pow(2, N - 1);
	long long start = 0;
	while (div>0) {
		start += r / div * num / 2 + c / div * num / 4;
		r %= div;
		c %= div;
		div /= 2;
		num /= 4;
	}
	cout << start << '\n';
}