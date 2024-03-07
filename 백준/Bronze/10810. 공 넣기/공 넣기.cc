#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);
	for (int i = 0; i < m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		for (int j = p; j <= q; j++) a[j] = r;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}