#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		int n; cin >> n;
		if (n == -1)break;
		int sum = 0;
		vector<int> a;
		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				sum += i; a.push_back(i);
			}
		}
		if (sum != n) cout << n << " is NOT perfect.\n";
		else {
			cout << n << " =";
			for (int i = 0; i < a.size(); i++) {
				cout << " " << a[i];
				if (i == a.size() - 1) continue;
				cout << " +";
			}
			cout << '\n';
		}
	}
}