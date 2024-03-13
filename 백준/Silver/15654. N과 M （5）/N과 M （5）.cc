#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;
vector<int> result;
int visited[10];

void dfs() {
	if (result.size() == m) {
		for (int num : result) cout << num << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		result.push_back(a[i]);
		visited[i] = 1;
		dfs();
		visited[i] = 0;
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	dfs();
}