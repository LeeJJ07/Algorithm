#include <iostream>
using namespace std;

int n, m, len;
int a[54][54];
bool check(int L) {
	for (int i = 0; i < n - L; i++) {
		for (int j = 0; j < m - L; j++) {
			int value = a[i][j];
			if (value == a[i + L][j] && value == a[i][j + L]
				&& value == a[i + L][j + L])
				return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j] - '0';
		}
	}
	for (len = min(n, m) - 1; len >= 0; len--) {
		if (check(len)) break;
	}
	cout << (len + 1) * (len + 1) << "\n";
}
