#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t, n, m, p[1004], cnt[1004], visited[1004], ed, s, e;

void bfs(vector<int> v[1004]) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q.push(i); visited[i] = p[i];
		}
	}
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i : v[now]) {
			cnt[i]--;
			visited[i] = max(visited[i], visited[now] + p[i]);
			if (cnt[i]) continue;
			q.push(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		vector<int> v[1004];
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 0; i < m; i++) {
			cin >> s >> e;
			v[s].push_back(e);
			cnt[e]++;
		}
		cin >> ed;
		bfs(v);
		cout << visited[ed] << '\n';
	}
}