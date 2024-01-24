#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<Node> my;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;

		while (my.size() && my.back().first > now) {
			my.pop_back();
		}
		my.push_back(Node(now, i));

		if (my.front().second <= i - L) {
			my.pop_front();
		}
		cout << my.front().first << " ";
	}
}