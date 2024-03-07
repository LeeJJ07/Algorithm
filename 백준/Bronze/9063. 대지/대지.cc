#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	int mxx = -10001, mxy = -10001, mnx = 10001, mny = 10001;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mxx = max(mxx, a);
		mnx = min(mnx, a);
		mxy = max(mxy, b);
		mny = min(mny, b);
	}
	cout << (mxx - mnx) * (mxy - mny);
}