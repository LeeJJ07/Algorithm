#include <iostream>

using namespace std;

int N;
int m[11][11];
int visited[11][11];
int dy[] = { 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, 1, 0, -1 };
int sum;
int result = 4000;

bool check(int y, int x) {
	for (int i = 0; i < 5; i++) {
		if (visited[y + dy[i]][x + dx[i]]) return false;
	}
	return true;
}
void add(int y, int x) {
	for (int i = 0; i < 5; i++) {
		visited[y + dy[i]][x + dx[i]] = 1;
		sum += m[y + dy[i]][x + dx[i]];
	}
}
void sub(int y, int x) {
	for (int i = 0; i < 5; i++) {
		visited[y + dy[i]][x + dx[i]] = 0;
		sum -= m[y + dy[i]][x + dx[i]];
	}
}

void DFS(int depth) {
	if (depth == 3) {
		result = min(result, sum);
		return;
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (check(i, j)) {
				add(i, j);
				DFS(depth + 1);
				sub(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}
	DFS(0);
	cout << result << '\n';
}