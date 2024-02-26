#include <iostream>
using namespace std;

int check(int a[]) {
	if (a[0] == 1) {
		for (int i = 1; i <= 8; i++) {
			if (a[i - 1] != i) return -1;
		}
		return 1;
	}
	else if (a[0] == 8) {
		for (int i = 8; i >= 1; i--) {
			if (a[8 - i] != i) return -1;
		}
		return 2;
	}
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a[8];
	for (int i = 0; i < 8; i++) cin >> a[i];
	if (check(a) == 1) cout << "ascending\n";
	else if (check(a) == 2)cout << "descending\n";
	else cout << "mixed\n";
}