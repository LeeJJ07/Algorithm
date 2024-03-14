#include <iostream>
#include <vector>
using namespace std;

int t, n, m, a, b, visited[1004], cnt;
vector<int> adj[1004];
void dfs(int here) {
	visited[here] = 1;
	for (int there : adj[here]) {
		if (visited[there]) continue;
		dfs(there);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1004; i++) adj[i].clear();
		fill(visited, visited + 1004, 0);
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[b].push_back(a);
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i])continue;
			dfs(i);
			cnt++;
		}
		if (m == n - 1 && cnt == 1)cout << "tree\n";
		else cout << "graph\n";
	}
}