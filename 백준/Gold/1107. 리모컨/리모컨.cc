#include <iostream>
#include <cmath>
using namespace std;

int n, m, num, check[10], z, cnt;
int zari(int num) {
	int c = 1;
	while (num / 10) {
		if (check[num % 10]) return -1;
		num /= 10;
		c++;
	}
	if (check[num % 10])return -1;
	return c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num; check[num] = 1;
	}
	
	int res = abs(100 - n);
	for (int i = 0; i <= 1000000; i++) {
		cnt = zari(i);
		if (cnt == -1) continue;
		cnt += abs(n - i);
		res = min(cnt, res);
	}
	cout << res << '\n';
}