#include <iostream>
using namespace std;
int n;

bool chk(int num) {
	int res = num;
	while (num > 0) {
		res += num % 10;
		num /= 10;
	}
	return res == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int result = 0;
	for (int i = n - 55; i <= n; i++) {
		if (chk(i)) {result = i; break;}
	}
	cout << result << '\n';
}