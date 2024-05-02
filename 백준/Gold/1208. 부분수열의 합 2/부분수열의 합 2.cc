#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, s, arr[41];
long long cnt;
map<int, int> m;

void left(int st, int sum) {
	if (st == n / 2) {
		m[sum]++;
		return;
	}
	left(st + 1, sum);
	left(st + 1, sum + arr[st]);
}
void right(int st, int sum) {
	if (st == n) {
		cnt += m[s - sum];
		return;
	}
	right(st + 1, sum);
	right(st + 1, sum + arr[st]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	left(0, 0);
	right(n / 2, 0);
	
	if (s == 0) cout << cnt - 1;
	else cout << cnt;
}