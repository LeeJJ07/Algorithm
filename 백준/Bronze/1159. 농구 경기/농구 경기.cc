#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> count(26, 0);
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		count[name[0] - 'a']++;
	}
	bool find = false;
	vector<char> result;
	for (int i = 0; i < 26; i++) {
		if (count[i] >= 5) {
			result.push_back('a' + i);
			find = true;
		}
	}
	if (find) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
	else {
		cout << "PREDAJA" << '\n';
	}
}