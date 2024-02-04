#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> A;
	vector<int> indegree;

	A.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		indegree[e]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int next : A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}