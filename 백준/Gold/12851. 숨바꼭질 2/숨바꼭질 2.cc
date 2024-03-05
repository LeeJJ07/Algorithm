#include <iostream>
#include <queue>

using namespace std;

int N, K;
const int MAX = 100004;
int visited[MAX];
int cnt[MAX];

void BFS() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	cnt[N] = 1;
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int next : {now + 1, now - 1, now * 2}) {
			if (next < 0 || next >= MAX) continue;
			if (!visited[next]) {
				q.push(next);
				visited[next] = visited[now] + 1;
				cnt[next] += cnt[now];
			}
			else if (visited[next] == visited[now] + 1) {
				cnt[next] += cnt[now];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	BFS();
	cout << visited[K] - 1 << '\n';
	cout << cnt[K] << '\n';
	return 0;
}