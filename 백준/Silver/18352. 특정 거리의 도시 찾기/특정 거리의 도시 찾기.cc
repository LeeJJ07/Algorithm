#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int>result;
static vector<int>visited;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	A.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		visited[i] = -1;
	}

	BFS(X);

	for (int i = 1; i <= N; i++) {
		if (visited[i] == K) {
			result.push_back(i);
		}
	}

	if (result.empty()) {
		cout << -1 << "\n";
	}
	else {
		sort(result.begin(), result.end());
		for (int temp : result) {
			cout << temp << "\n";
		}
	}
}
void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node]++;

	while (!q.empty()) {
		int new_node = q.front();
		q.pop();
		for (int i : A[new_node]) {
			if (visited[i] != -1)
				continue;
			q.push(i);
			visited[i] = visited[new_node] + 1;
		}
	}
}