#include <iostream>
#include <vector>
using namespace std;

void DFS(int node);
static vector<vector<int>> tree;
static vector<bool> visited;
static int result;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	tree.resize(N);
	visited.resize(N);
	int root;
	for (int i = 0; i < N; i++) {
		int node;
		cin >> node;
		if (node == -1) {
			root = i;
			continue;
		}
		tree[node].push_back(i);
	}
	int era;
	cin >> era;

	visited[era] = true;
	
	result = 0;
	if (era == root) {
		cout << 0 << "\n";
	}
	else {
		DFS(root);
		cout << result << "\n";
	}
}
void DFS(int node) {
	visited[node] = true;
	int count = 0;
	for (int i : tree[node]) {
		if (visited[i])
			continue;
		DFS(i);
		count++;
	}
	if(count==0)
		result++;
}