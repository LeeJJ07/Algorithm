#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool tri(int a, int b, int c) {
	if (c * c == a * a + b * b)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		vector<int>a(3);
		for (int i = 0; i < 3; i++) cin >> a[i];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
		sort(a.begin(), a.end());
		if (tri(a[0], a[1], a[2])) cout << "right\n";
		else cout << "wrong\n";
	}
}