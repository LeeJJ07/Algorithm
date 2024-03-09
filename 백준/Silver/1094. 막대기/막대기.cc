#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;
	int result = 0;
	for (int i = 0; i <= 6; i++) {
		if (x & (1 << i)) result++;
	}
	cout << result;
}