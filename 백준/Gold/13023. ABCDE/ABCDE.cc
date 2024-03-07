#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;
bool result;

void DFS(int there, int depth) {
	if (depth == 5 || result) {
		result = true;
		return;
	}

	for (int here : adj[there]) {
		if (visited[here]) continue;
		visited[here] = 1;
		DFS(here, depth + 1);
		visited[here] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	
	adj.resize(n);
	visited.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	result = false;
	for (int i = 0; i < n; i++) {
		if (result) break;
		visited[i] = 1;
		DFS(i, 1);
		visited[i] = 0;
	}
	if (result) cout << 1 << '\n';
	else cout << 0 << '\n';
}