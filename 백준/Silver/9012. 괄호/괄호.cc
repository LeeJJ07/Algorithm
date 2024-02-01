#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		bool result = true;
		stack<char> myStack;
		for (int j = 0; j < str.size(); j++) {
			if (myStack.empty()) {
				if (str[j] == '(') {
					myStack.push(str[j]);
				}
				else if (str[j] == ')') {
					result = false;
					break;
				}
			}
			else {
				if (str[j] == '(')
					myStack.push(str[j]);
				else
					myStack.pop();
			}
		}
		if (!myStack.empty())
			result = false;
		
		if (result) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}