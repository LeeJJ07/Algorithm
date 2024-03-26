#include <iostream>
#include <map>
using namespace std;
int t, n, m, num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		map<int, int> mp;
		cin >> n;
		while (n--) {
			cin >> num;
			mp[num] = 1;
		}
		cin >> m;
		while (m--) {
			cin >> num;
			cout << mp[num] << '\n';
		}
	}
}