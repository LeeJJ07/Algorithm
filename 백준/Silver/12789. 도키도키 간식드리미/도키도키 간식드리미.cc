#include <iostream>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int idx = 1;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.push(num);
		while (s.size() && s.top() == idx) {
			s.pop(); idx++;
		}
	}
	if (s.empty())cout << "Nice";
	else cout << "Sad";
}