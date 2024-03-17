#include <iostream>
using namespace std;

bool sosu(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	if (m == 1) m = 2;
	int result = -1;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (sosu(i)) {
			if (result == -1) result = i;
			sum += i;
		}
	}
	if (result == -1)cout << result << '\n';
	else cout << sum << '\n' << result << '\n';
}