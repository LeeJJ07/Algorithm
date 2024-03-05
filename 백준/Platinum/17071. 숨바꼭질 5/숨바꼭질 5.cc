#include <iostream>
#include <queue>

using namespace std;

int N, K;
const int MAX = 500000;
int visited[2][MAX + 4], a, b, turn = 1;
bool BFS() {
	queue<int>q;
	q.push(a);
	while (q.size()) {
		b += turn;
		if (b > MAX)break;
		if (visited[turn % 2][b]) return true;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();
			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx<0 || nx>MAX || visited[turn % 2][nx])continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == b) return true;
				q.push(nx);
			}
		}
		turn++;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	if (a == b) { cout << 0 << '\n'; return 0; }
	if (BFS())cout << turn << '\n';
	else cout << -1 << '\n';
	return 0;
}