#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
const int MAX = 100004;
int visited[MAX];
vector<int> result;
void BFS() {
	queue<int> q;
	visited[N] = 1;
	q.push(N);
	while (q.size()) {
		int now = q.front();
		if (now == K) break;
		q.pop();
		for (int next : {now + 1, now - 1, now * 2}) {
			if (next < 0 || next >= MAX) continue;
			if (visited[next]) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
	int level = visited[K];
	int num = K;
	while (true) {
		result.push_back(num);
		if (num == N)break;
		level--;
		if (num - 1 >= 0 && visited[num-1] == level) {
			num--;
		}
		else if (num + 1 < MAX && visited[num + 1] == level) {
			num++;
		}
		else if (num % 2 == 0 && num / 2 != 0 && visited[num / 2] == level) {
			num /= 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	BFS();
	cout << visited[K]-1 << '\n';
	for (int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
	return 0;
}