#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int node);
static int N, M, R;
static vector<vector<int>> A;
static vector<int> visited;
static int level;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> R;
	A.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	level = 1;
	DFS(R);
	
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << "\n";
	}
}
void DFS(int node) {
	visited[node] = level++;
	sort(A[node].begin(), A[node].end());
	for (int i : A[node]) {
		if (visited[i]!=0)
			continue;
		DFS(i);
	}
}