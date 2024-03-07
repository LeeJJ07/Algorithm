#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (a >= b + c || b >= a + c || c >= a + b) cout << "Invalid\n";
		else if (a == b && b == c) cout << "Equilateral\n";
		else if (a != b && b != c && c != a) cout << "Scalene\n";
		else cout << "Isosceles\n";
	}
}