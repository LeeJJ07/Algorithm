#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int n, op, x; cin >> n;
	while (n--) {
		cin >> op;
		switch (op) {
		case 1:
			cin >> x; dq.push_front(x);
			break;
		case 2:
			cin >> x; dq.push_back(x);
			break;
		case 3:
			if (dq.size()) { cout << dq.front() << '\n'; dq.pop_front(); }
			else cout << -1 << '\n';
			break;
		case 4:
			if (dq.size()) { cout << dq.back() << '\n'; dq.pop_back(); }
			else cout << -1 << '\n';
			break;
		case 5:
			cout << dq.size() << '\n';
			break;
		case 6:
			cout << dq.empty() << '\n';
			break;
		case 7:
			if (dq.size()) cout << dq.front() << '\n';
			else cout << -1 << '\n';
			break;
		case 8:
			if (dq.size()) cout << dq.back() << '\n';
			else cout << -1 << '\n';
			break;
		}
	}
}