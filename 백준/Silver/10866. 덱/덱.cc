#include <iostream>
#include <queue>
using namespace std;

int n, x;
string str;
deque<int> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push_front") {
			cin >> x; d.push_front(x);
		}
		else if (str == "push_back") {
			cin >> x; d.push_back(x);
		}
		else if (str == "pop_front") {
			if (d.size()) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (str == "pop_back") {
			if (d.size()) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (str == "size") {
			cout << d.size() << '\n';
		}
		else if (str == "empty") {
			cout << d.empty() << '\n';
		}
		else if (str == "front") {
			if (d.size()) cout << d.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (str == "back") {
			if (d.size()) cout << d.back() << '\n';
			else cout << -1 << '\n';
		}
	}
}