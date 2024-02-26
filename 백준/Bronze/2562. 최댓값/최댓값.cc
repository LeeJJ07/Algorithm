#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int max = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		if (max < num) {
			max = num;
			idx = i;
		}
	}
	cout << max << '\n';
	cout << idx+1 << '\n';
}