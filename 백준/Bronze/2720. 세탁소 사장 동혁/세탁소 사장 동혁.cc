#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//25, 10, 5, 1
	int a[] = { 25, 10, 5, 1 };
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < 4; i++) {
			cout << n / a[i] << ' ';
			n %= a[i];
		}
		cout << '\n';
	}
}