#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N, M;
	cin >> T;
	
	while (T--) {
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			q.push({ i , num });
			pq.push(num);
		}
		int count = 0;
		while (q.size()) {
			pair<int, int> now = q.front();
			q.pop();
			if (now.second == pq.top()) {
				count++;
				pq.pop();
				if (now.first == M) {
					cout << count << '\n';
					break;
				}
			}
			else q.push(now);
		}
	}
}