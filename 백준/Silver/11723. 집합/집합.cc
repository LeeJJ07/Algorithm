#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> S;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string input; int x;
		cin >> input;
		bool find = false;
		if (input == "add") {
			cin >> x;
			S.insert(x);
		}
		else if (input == "remove") {
			cin >> x;
			S.erase(x);
		}
		else if (input == "check") {
			cin >> x;
			for (int s : S) {
				if (s == x) {
					find = true;
					break;
				}
			}
			if (find) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (input == "toggle") {
			cin >> x;
			for (int s : S) {
				if (s == x) {
					find = true;
					break;
				}
			}
			if (find) {
				S.erase(x);
			}
			else {
				S.insert(x);
			}
		}
		else if (input == "all") {
			for (int i = 1; i <= 20; i++)
				S.insert(i);
		}
		else if (input == "empty") {
			S.clear();
		}
	}
}