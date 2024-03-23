#include <iostream>
#include <vector>
#include <map>
using namespace std;

int a[1001], b[1001], ret, psum_a[2002], psum_b[2002], want, n, m;
map<int, int> aCnt, bCnt;
void make(int n, int psum[], map<int, int>& mp) {
	for (int interval = 1; interval <= n; interval++) {
		for (int start = interval; start <= n + interval - 1; start++) {
			int sum = psum[start] - psum[start - interval];
			mp[sum]++;
			if (interval == n)break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> want >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n];
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}
	for (int i = m + 1; i <= 2 * m; i++) psum_b[i] = psum_b[i - 1] + b[i - m];
	make(n, psum_a, aCnt);
	make(m, psum_b, bCnt);
	ret = (aCnt[want] + bCnt[want]);
	for (int i = 1; i < want; i++) {
		ret += (aCnt[i] * bCnt[want - i]);
	}
	cout << ret << '\n';
}