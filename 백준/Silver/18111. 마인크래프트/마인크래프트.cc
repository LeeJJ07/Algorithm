#include <iostream>
using namespace std;

int n, m, b;
int a[257];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> b;
	int res = 98765432;
	int resH = 0;
	int sz = n * m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num; cin >> num;
			a[num]++;
		}
	}
	for (int i = 256; i >= 0; i--) {
		int build = 0, remove = 0;
		for (int j = 256; j >= 0; j--) {
			int height = i - j;
			if (height > 0) build += a[j] * height;
			else if (height < 0) remove -= a[j] * height;
		}
		if (remove + b >= build) {
			int t = remove * 2 + build;
			if (res > t) {
				res = t;
				resH = i;
			}
		}
	}
	cout << res << ' ' << resH << '\n';
}