#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		stack <char> myStack;
		myStack.push(str[0]);
		for (int j = 1; j < str.size(); j++) {
			if (myStack.empty()) {
				myStack.push(str[j]);
				continue;
			}
			if (myStack.top() == str[j]) {
				myStack.pop();
			}
			else {
				myStack.push(str[j]);
			}
		}
		if (myStack.empty())
			result++;
	}
	cout << result << "\n";
}