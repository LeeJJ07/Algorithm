#include <iostream>
#include <queue>
using namespace std;

int n, m, mv[101], u, v, visited[101];
int bfs() {
	int res = 1;
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (q.size()) {
		int sz = q.size();
		for (int k = 0; k < sz; k++) {
			int now = q.front();
			q.pop();
			for (int i = 1; i <= 6; i++) {
				if (i + now > 100) continue;
				if (i + now == 100) return res;
				int next = mv[i + now];
				if (visited[next]) continue;
				visited[next] = 1;
				q.push(next);
			}
		}
		res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i < 101; i++) mv[i] = i;
	cin >> n >> m;
	int t = n + m;
	while (t--) {
		cin >> u >> v;
		mv[u] = v;
	}
	cout << bfs() << '\n';
}