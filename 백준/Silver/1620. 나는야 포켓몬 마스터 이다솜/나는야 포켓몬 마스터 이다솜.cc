#include <iostream>
#include <map>
#include <string>
using namespace std;

bool is_digit(string str) {
	return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<int, string> name;
	map<string, int> number;
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		name[i] = input;
		number[input] = i;
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		if (is_digit(input)) {
			auto item = name.find(atoi(input.c_str()));
			cout << item->second << '\n';
		}
		else {
			auto item = number.find(input);
			cout << item->second << '\n';
		}
	}
}