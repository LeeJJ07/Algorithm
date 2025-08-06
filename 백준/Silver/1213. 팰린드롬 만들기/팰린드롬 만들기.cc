#include <vector>
#include <iostream>

using namespace std;

vector<int> alpha(26);
string str;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	for (int i = 0;i < str.size();i++)
		alpha[str[i] - 'A']++;

	vector<char> result(str.size());
	int idx = 0;
	for (int i = 0; i < 26;i++) {
		if (alpha[i] == 0) continue;
		if ((alpha[i] % 2) && result[str.size() / 2]) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
		while (alpha[i]) {
			if (alpha[i] == 1) {
				result[str.size() / 2] = i + 'A';
				alpha[i]--;
			}
			else {
				result[idx] = i + 'A';
				result[result.size() - 1 - idx] = i + 'A';
				alpha[i] -= 2;
				idx++;
			}
		}
	}
	for (char c : result)
		cout << c;
}