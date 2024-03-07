#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 == x2) cout << x3 << ' ';
	else if (x2 == x3) cout << x1 << ' ';
	else cout << x2 << ' ';
	if (y1 == y2) cout << y3;
	else if (y2 == y3) cout << y1;
	else cout << y2;
}