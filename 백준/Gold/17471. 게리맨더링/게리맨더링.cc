#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int n;
vector<map<int, int>>adj;
int visited[11];
int popu[11];
int result = 10000;

void bfs(vector<int> v) {
	queue<int> q;
	q.push(v[0]);
	visited[v[0]] = 1;
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int next : v) {
			if (visited[next]) continue;
			if (!adj[now][next]) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
}

void chk(vector<int> v1, vector<int> v2) {
	fill(&visited[0], &visited[11], 0);
	bfs(v1); bfs(v2);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) return;
	}
	int res1 = 0, res2 = 0;
	for (int i : v1) res1 += popu[i];
	for (int i : v2) res2 += popu[i];
	result = min(result, abs(res1 - res2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> popu[i];
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int v; cin >> v;
			adj[i][v] = 1;
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++) {
		vector<int> v1;
		vector<int> v2;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) v1.push_back(j + 1);
			else v2.push_back(j + 1);
		}
		chk(v1, v2);
	}
	if (result == 10000) cout << -1 << '\n';
	else cout << result << '\n';
}
