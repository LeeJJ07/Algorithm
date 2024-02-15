#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	vector<int> pl(26);
	for (int i = 0; i < input.length(); i++) {
		pl[input[i]-'A']++;
	}

	int holcount = 0;
	for (int i = 0; i < 26; i++) {
		if (pl[i] % 2 == 1) {
			holcount++;
		}
	}
	vector<char> result(input.length());
	int index = 0;
	if (holcount > 1) {
		cout << "I'm Sorry Hansoo" << '\n';
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (pl[i] == 0)
				continue;
			if (pl[i] % 2 == 1) {
				result[result.size() / 2] = 'A' + i;
				pl[i--]--;
			}
			else {
				result[index] = 'A' + i;
				result[result.size() - 1 - index] = 'A' + i;
				pl[i--] -= 2;
				index++;
			}
		}
		for (char c : result) cout << c;
		cout << '\n';
	}
}