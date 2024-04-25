#include <iostream>
using namespace std;
typedef long long ll;
ll go(ll n) {
	if (n == 1 || n == 0) return 1;
	return go(n - 1) * n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n; cin >> n;
	cout << go(n) << "\n";
}