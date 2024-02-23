#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int o1, int o2) {
		int r1 = abs(o1);
		int r2 = abs(o2);
		if (r1 == r2) {
			return o1 > o2;
		}
		else {
			return r1 > r2;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, cmp> q;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		if (num == 0) {
			if (q.empty())
				cout << "0\n";
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(num);
		}
	}
}