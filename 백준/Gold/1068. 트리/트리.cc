#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> visited;
int result = 0;
void DFS(int s) {
	visited[s] = 1;
	if (tree[s].empty()) result++;
	for (int i : tree[s]) {
		if (visited[i]) continue;
		DFS(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	tree.resize(N);
	visited.resize(N);
	vector<int> temp(N);
	int root = -1;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		temp[i] = p;
	}
	int del;
	cin >> del;
	for (int i = 0; i < N; i++) {
		if (i == del) continue;
		if (temp[i] == -1) {
			root = i;
			continue;
		}
		tree[temp[i]].push_back(i);
	}
	if (root == -1) cout << 0 << '\n';
	else {
		DFS(root);
		cout << result << '\n';
	}
}