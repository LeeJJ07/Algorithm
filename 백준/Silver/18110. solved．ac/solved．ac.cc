#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int u = round((double)n / 100 * 15);
	int sum = 0; double avg = 0;
	for (int i = u; i < n - u; i++) {
		sum += a[i];
	}
	if (n == 0) cout << 0 << '\n';
	else {
		avg = (double)sum / (n - 2 * u);
		cout << round(avg) << '\n';
	}
}