#include <iostream>
#include <vector>
using namespace std;

void DFS(int node);
static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		visited.resize(V + 1);
		check.resize(V + 1);
		IsEven = true;

		for (int i = 0; i < E; i++) {
			int s, e;
			cin >> s >> e;
			A[s].push_back(e);
			A[e].push_back(s);
		}
		for (int i = 1; i <= V; i++) {
			if (IsEven) {
				DFS(i);
			}
			else {
				break;
			}
		}
		if (IsEven) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		for (int i = 0; i <= V; i++) {
			A[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
}
void DFS(int node) {
	visited[node] = true;

	for (int i : A[node]) {
		if (!visited[i]) {
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		else if (check[node] == check[i]) {
			IsEven = false;
			return;
		}
	}
}