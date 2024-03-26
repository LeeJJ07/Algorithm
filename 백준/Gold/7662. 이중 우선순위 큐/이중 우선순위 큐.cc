#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k, n;
	char c;
	cin >> t;
	while (t--) {
		multiset<int> ms;
		cin >> k;
		while (k--) {
			cin >> c >> n;
			if (c == 'I') ms.insert(n);
			else {
				if (ms.empty()) continue;
				if (n == -1) ms.erase(ms.begin()); 
				else { ms.erase(--ms.end()); }
			}
		}
		if (ms.empty()) cout << "EMPTY" << '\n';
		else {
			auto iter = --ms.end();
			cout << *iter << ' ' << *ms.begin() << '\n';
		}
	}
}