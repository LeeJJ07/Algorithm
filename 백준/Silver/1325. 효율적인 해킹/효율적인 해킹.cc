#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int>result;
static vector<bool>visited;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int E, S;
		cin >> E >> S;
		A[S].push_back(E);
	}

	result.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}
	int maxV = -1;
	for (int i = 1; i <= N; i++) {
		maxV = max(maxV, result[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (result[i] == maxV) {
			cout << i << " ";
		}
	}
}
void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		int new_node = q.front();
		q.pop();
		for (int i : A[new_node]) {
			if (visited[i])
				continue;
			visited[i] = true;
			result[node]++;
			q.push(i);
		}
	}
}