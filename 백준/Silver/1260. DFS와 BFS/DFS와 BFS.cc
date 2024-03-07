#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, start;
vector<vector<int>> adj;
vector<int> visited;

void DFS(int there) {
	visited[there] = 1;
	cout << there << ' ';
	for (int here : adj[there]) {
		if (visited[here]) continue;
		DFS(here);
	}
}
void BFS(int there) {
	queue<int> q;
	q.push(there);
	visited[there] = 1;
	while (q.size()) {
		int now = q.front();
		cout << now << ' ';
		q.pop();
		for (int next : adj[now]) {
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> start;
	
	adj.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	DFS(start);
	cout << '\n'; fill(visited.begin(), visited.end(), 0);
	BFS(start);
}