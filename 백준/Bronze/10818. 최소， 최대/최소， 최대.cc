#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	int mn = 1000001;
	int mx = -1000001;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (mn > num) mn = num;
		if (mx < num) mx = num;
	}
	cout << mn << " " << mx << '\n';
}