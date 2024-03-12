#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int start5 = n / 5;
	int start3 = 0;
	while (start5 >= 0) {
		int num = n - start5 * 5;
		start3 = num / 3;
		if (num % 3 == 0) break;
		start5--;
	}
	if (start5 == -1) cout << start5 << '\n';
	else cout << start5 + start3 << '\n';
}