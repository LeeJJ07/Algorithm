#include <iostream>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	if (n == 0) cout << 1 << '\n';
	else {
		int res = 1;
		for (int i = 2; i <= n; i++) res *= i;
		cout << res << '\n';
	}
}