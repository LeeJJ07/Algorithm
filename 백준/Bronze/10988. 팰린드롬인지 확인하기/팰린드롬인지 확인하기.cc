#include <iostream>
#include <vector>
using namespace std;

bool isPD(string input) {
	int mid = input.length() / 2;

	for (int i = 0; i < mid; i++) {
		if (input[i] != input[input.length()-1-i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	if (isPD(str)) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}