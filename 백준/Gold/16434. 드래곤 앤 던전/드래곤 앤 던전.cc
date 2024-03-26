#include <iostream>
using namespace std;
typedef long long ll;
ll n, attack, t, a, h, mx;
ll inf[123458][3];
ll v[123458];

bool check(ll mid) {
	ll maxHP = mid;
	for (int i = 0; i < n; i++) {
		if (inf[i][0] == 1) {
			mid -= v[i];
			if (mid <= 0) return false;
		}
		else {
			mid += v[i];
			if (mid > maxHP) mid = maxHP;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> attack;
	for (int i = 0; i < n; i++) {
		cin >> inf[i][0] >> inf[i][1] >> inf[i][2];
		if (inf[i][0] == 1) {
			if (inf[i][2] % attack == 0) {
				mx += (inf[i][2] / attack - 1) * inf[i][1];
				v[i] = (inf[i][2] / attack - 1) * inf[i][1];
			}
			else {
				mx += (inf[i][2] / attack) * inf[i][1];
				v[i] = (inf[i][2] / attack) * inf[i][1];
			}
		}
		else {
			attack += inf[i][1];
			v[i] = inf[i][2];
		}
	}
	ll lo = 1, hi = mx+1, mid, ret = 1e18;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << '\n';
}