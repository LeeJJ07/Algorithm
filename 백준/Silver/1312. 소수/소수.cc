#include <iostream>
using namespace std;

int a, b, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> n;
	a %= b;
	int num = a;
	while (n--) {
		a *= 10;
		num = a / b;
		a %= b;
	}
	cout << num << "\n";
}