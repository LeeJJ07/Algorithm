#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n;
int a[104][104];
int visited[104];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (visited[i] || !a[now][i])continue;
			visited[i] = 1;
			q.push(i);
			a[s][i] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}