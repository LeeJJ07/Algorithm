#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A;
vector<bool> visited;
int result;

void DFS(int s) {

	visited[s] = true;
	for (int i : A[s]) {
		if (visited[i])
			continue;
		result++;
		DFS(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	A.resize(N + 1);
	visited.resize(N + 1, false);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	result = 0;
	DFS(1);
	cout << result << '\n';
}