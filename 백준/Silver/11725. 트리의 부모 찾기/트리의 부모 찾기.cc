#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int root);
static vector<vector<int>> A;
static vector<int> result;
static vector<bool> visited;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	A.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	
	visited = vector<bool>(N + 1, false);
	result = vector<int>(N + 1, 0);

	BFS(1);

	for (int i = 2; i <= N; i++) {
		cout << result[i] << "\n";
	}
	
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	visited[root] = true;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();
		for (int i : A[now_node]) {
			if (visited[i])
				continue;
			result[i] = now_node;
			visited[i] = true;
			q.push(i);
		}
	}
}