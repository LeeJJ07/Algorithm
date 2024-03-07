#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c <= 2 * max(max(a, b), c))
		cout << (a + b + c - max(max(a, b), c)) * 2 - 1;
	else cout << a + b + c;
}