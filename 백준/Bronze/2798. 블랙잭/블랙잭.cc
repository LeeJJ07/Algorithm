#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int result = 300005;
	int resNum = 0;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (m >= (a[i] + a[j] + a[k]) && result > m - (a[i] + a[j] + a[k])) {
					result = min(m - (a[i] + a[j] + a[k]), result);
					resNum = a[i] + a[j] + a[k];
				}
			}
		}
	}
	cout << resNum << '\n';
}