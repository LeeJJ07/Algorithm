#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string qs;
		cin >> qs;
		if (qs.compare("push")==0) {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (qs.compare("pop")==0) {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				int num = q.front();
				q.pop();
				cout << num << "\n";
			}
		}
		else if (qs.compare("size")==0) {
			cout << q.size() << "\n";
		}
		else if (qs.compare("empty")==0) {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (qs.compare("front")==0) {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (qs.compare("back")==0) {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}