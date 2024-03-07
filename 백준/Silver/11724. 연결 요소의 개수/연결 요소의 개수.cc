#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int n, m;

void DFS(int there) {
	visited[there] = 1;
	for (int here : adj[there]) {
		if (visited[here])continue;
		DFS(here);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	adj.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		DFS(i);
		result++;
	}
	cout << result << '\n';
}