#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static vector<int> mdistance;
static vector<bool> visited;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	mdistance.resize(N + 1);
	std::fill(mdistance.begin(), mdistance.end(), INT_MAX);
	visited.resize(N + 1);
	std::fill(visited.begin(), visited.end(), false);
	mlist.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}
	int S, E;
	cin >> S >> E;
	mdistance[S] = 0;
	q.push(make_pair(0, S));

	while (!q.empty()) {
		edge now = q.top();
		q.pop();
		int c_v = now.second;
		if (visited[c_v])
			continue;
		visited[c_v] = true;
		for (edge tmp : mlist[c_v]) {
			int next = tmp.first;
			int value = tmp.second;

			if (mdistance[next] > mdistance[c_v] + value) {
				mdistance[next] = mdistance[c_v] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}
	cout << mdistance[E] << "\n";
}