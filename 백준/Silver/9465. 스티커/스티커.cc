#include <iostream>
#include <vector>
using namespace std;

int t, n;
int result = 0;
vector<vector<int>> a;
vector<vector<int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	a.resize(2);
	s.resize(2);
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			a[i].resize(n);
			s[i].resize(n);
			fill(a[i].begin(), a[i].end(), 0);
			fill(s[i].begin(), s[i].end(), 0);
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		s[0][0] = a[0][0]; s[1][0] = a[1][0];
		s[0][1] = s[1][0] + a[0][1];
		s[1][1] = s[0][0] + a[1][1];
		for (int i = 2; i < n; i++) {
			s[0][i] = a[0][i] + max(s[1][i - 2], s[1][i - 1]);
			s[1][i] = a[1][i] + max(s[0][i - 2], s[0][i - 1]);
		}
		int n1 = max(s[0][n - 1], s[0][n - 2]);
		int n2 = max(s[1][n - 1], s[1][n - 2]);
		cout << max(n1, n2) << '\n';
	}
}