#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	while ((int)sqrt(n) * (int)sqrt(n) != n) {
		n--;
	}
	cout << sqrt(n) << '\n';
}