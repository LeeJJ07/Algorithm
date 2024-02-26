#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int clo = -1;
		for (int j = 0; j < M; j++) {
			if (str[j] == 'c') clo = 0;
			else if (clo != -1) clo++;
			cout << clo << ' ';
		}
		cout << '\n';
	}
}