#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a[15] = { 3, };
	for (int i = 1; i < 15; i++) {
		a[i] = a[i - 1] * 2 - 1;
	}
	int n; cin >> n;
	cout << a[n - 1] * a[n - 1] << '\n';
}