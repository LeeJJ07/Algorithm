#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[1000001];

void bfs() {
	queue<int> q;
	q.push(n);
	dp[n] = 0;
	int level = 1;
	while (q.size()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int now = q.front();
			q.pop();
			for (int j = 0; j < 3; j++) {
				int nw = 0;
				if (j == 0 && now % 3 == 0) nw = now / 3;
				else if (j == 1 && now % 2 == 0)nw = now / 2;
				else if (j == 2) nw = now - 1;
				else continue;
				if (nw == 1) {
					dp[nw] = now; cout << level << '\n';
					return;
				}
				if (dp[nw])continue;
				dp[nw] = now;
				q.push(nw);
			}
		}
		level++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n' << 1 << '\n';
		return 0;
	}
	bfs();
	vector<int> res;
	for (int i = 1; i != n; i = dp[i]) {
		res.push_back(i);
	}
	res.push_back(n);
	reverse(res.begin(), res.end());
	for (int i : res) cout << i << " ";
}