#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int t = 0; t < N; t++) {
		string str;
		cin >> str;
		int o = 0;
		int result = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'O') o++;
			else o = 0;
			result += o;
		}
		cout << result << '\n';
	}
}