#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int> answer;
static vector<int> visited;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	A.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
	}
	visited.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		visited[i] = -1;
	}

	BFS(X);

	for (int i = 1; i <= N; i++) {
		if (visited[i] == K) {
			answer.push_back(i);
		}
	}
	sort(answer.begin(), answer.end());

	if (answer.empty()) {
		cout << -1 << "\n";
	}
	else {
		sort(answer.begin(), answer.end());
		for (int temp : answer) {
			cout << temp << "\n";
		}
	}
}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node]++;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();
		for (int i : A[now_node]) {
			if (visited[i] == -1) {
				visited[i] = visited[now_node] + 1;
				q.push(i);
			}
		}
	}
}