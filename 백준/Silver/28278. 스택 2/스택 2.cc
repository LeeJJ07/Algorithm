#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack <int>A;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		switch (num) {
		case 1:
			int X;
			cin >> X;
			A.push(X);
			break;
		case 2:
			if (A.empty())
				cout << -1 << "\n";
			else {
				int n = A.top();
				A.pop();
				cout << n << "\n";
			}
			break;
		case 3:
			cout << A.size()<<"\n";
			break;
		case 4:
			if (A.empty()) {
				cout << 1<<"\n";
			}
			else {
				cout << 0 << "\n";
			}
			break;
		case 5:
			if (A.empty())
				cout << -1 << "\n";
			else {
				cout << A.top() << "\n";
			}
			break;
		}
	}
}