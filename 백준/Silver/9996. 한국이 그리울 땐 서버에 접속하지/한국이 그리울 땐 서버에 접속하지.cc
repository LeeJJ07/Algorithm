#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string input;
	cin >> input;
	string bufferflush;
	getline(cin, bufferflush);
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		bool result = true;

		int s = 0;
		int e1 = input.length() - 1;
		int e2 = str.length() - 1;
		while (input[s] != 42) {
			if (input[s] != str[s]) {
				result = false;
				break;
			}
			s++;
		}
		if (!result) {
			cout << "NE" << "\n";
			continue;
		}
		while (input[e1] != 42) {
			if (input[e1] != str[e2] || s - 1 == e2) {
				result = false;
				break;
			}
			e1--, e2--;
		}
		if (!result) {
			cout << "NE" << "\n";
		}
		else {
			cout << "DA" << "\n";
		}
	}
}