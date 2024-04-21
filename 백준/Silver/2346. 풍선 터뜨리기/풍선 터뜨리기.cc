#include <iostream>
#include <deque>
using namespace std;

int n, input;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input; dq.push_back({ input, i + 1 });
	}
	while (true) {
		pair<int, int> now = dq.front();
		dq.pop_front();
		cout << now.second << " ";
		if (dq.empty()) break;
		if (now.first > 0) {
			for (int i = 1; i < now.first; i++) {
				pair<int, int> next = dq.front();
				dq.push_back(next);
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < -now.first; i++) {
				pair<int, int> next = dq.back();
				dq.push_front(next);
				dq.pop_back();
			}
		}
	}
}