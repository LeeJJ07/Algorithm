#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
}
