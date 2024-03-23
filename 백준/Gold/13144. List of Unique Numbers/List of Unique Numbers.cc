#include <iostream>
#include <vector>
using namespace std;

int cnt[100001];
long long n, s, e, ret;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (e < n) {
		if (!cnt[v[e]]) {
			cnt[v[e++]]++;
		}
		else {
			ret += (e - s);
			cnt[v[s++]]--;
		}
	}
	ret += (e - s) * (e - s + 1) / 2;
	cout << ret << '\n';
}