#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
ll n, m, dp[101][10004];
vector<p> v;
bool cmp(p a, p b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}
int go() {
	int res = 10004;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (v[i - 1].second > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].second] + v[i - 1].first);
			if (dp[i][j] >= m) res = min(res, j);
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i].first;
	for (int i = 0; i < n; i++)cin >> v[i].second;

	sort(v.begin(), v.end(), cmp);
	cout << go() << '\n';
}