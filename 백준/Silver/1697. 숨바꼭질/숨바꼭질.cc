#include <iostream>
#include <queue>
using namespace std;

int N, K;
int check[100001];
bool valid(int n) {
	if (n < 0 || n>100000 || check[n] != 0)
		return false;
	return true;
}
void BFS() {
	queue<int> q;
	q.push(N);
	check[N] = 1;
	while (q.size()) {
		int now = q.front();
		q.pop();
		if (now == K) return;
		if (valid(now-1)) {
			check[now - 1] = check[now] + 1;
			q.push(now - 1);
		}if (valid(now + 1)) {
			check[now + 1] = check[now] + 1;
			q.push(now + 1);
		}if (valid(now * 2)) {
			check[now * 2] = check[now] + 1;
			q.push(now * 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	BFS();
	cout << check[K] - 1 << '\n';
}