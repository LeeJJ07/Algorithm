#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	while (n >1) {
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				cout << i << "\n";
				n /= i;
				break;
			}
		}
	}
}