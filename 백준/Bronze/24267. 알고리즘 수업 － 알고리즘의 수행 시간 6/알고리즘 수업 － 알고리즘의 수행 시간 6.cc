#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n; cin >> n;
	cout << n*(n-1)*(n-2)/6 << '\n' << 3 << '\n';
}