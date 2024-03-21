#include <iostream>
using namespace std;

int n, m, b, num, res = 98765432, resH = 0;
int a[257];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> b;
	for (int i = 0; i < n * m; i++) {
		cin >> num; a[num]++;
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