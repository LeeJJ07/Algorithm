#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> t(N + 1);
	vector<vector<int>> A(N + 1);
	vector<int> indegree(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		while (true) {
			int num;
			cin >> num;
			if (num == -1)
				break;
			A[num].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	vector<int> result(N + 1);
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : A[now]) {
			indegree[next]--;
			result[next] = max(result[next], result[now] + t[now]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << result[i] + t[i] << "\n";
	}
}