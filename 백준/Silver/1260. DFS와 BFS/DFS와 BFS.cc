#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int v);
void BFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S;
	cin >> N >> M >> S;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}
	DFS(S);
	cout << "\n";

	visited = vector<bool>(N + 1, false);
	
	BFS(S);
	cout << "\n";
}

void DFS(int v) {
	cout << v << " ";
	visited[v] = true;
	
	for (int i : A[v]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}
void BFS(int s) {
	
	queue<int>B;
	B.push(s);
	visited[s] = true;

	while (!B.empty()) {
		int num = B.front();
		cout << num << " ";
		B.pop();
		for (int i : A[num]) {
			if (!visited[i]) {
				B.push(i);
				visited[i] = true;
			}
		}
	}
}

