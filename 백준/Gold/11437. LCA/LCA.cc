#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

int executeLCA(int a, int b);
void BFS(int node);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	tree.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	BFS(1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = executeLCA(a, b);
		cout << LCA << "\n";
	}
}
int executeLCA(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (depth[a] != depth[b]) {
		a = parent[a];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

void BFS(int node) {
	queue<int> myQueue;
	myQueue.push(node);
	visited[node] = true;
	int level = 1;
	int now_size = 1;
	int count = 0;

	while (!myQueue.empty()) {
		int now_node = myQueue.front();
		myQueue.pop();

		for (int next : tree[now_node]) {
			if (visited[next])
				continue;
			visited[next] = true;
			myQueue.push(next);
			parent[next] = now_node;
			depth[next] = level;
		}
		count++;
		if (count == now_size) {
			count = 0;
			now_size = myQueue.size();
			level++;
		}
	}
}