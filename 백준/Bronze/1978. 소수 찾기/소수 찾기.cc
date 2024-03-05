#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[1001] = { 0, };
	a[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (a[i] == 0) {
			a[i] = 2;
			int num = i;
			while (num <= 1000) {
				if(a[num]==0) a[num] = 1;
				num += i;
			}
		}
	}
	int result = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (a[n] == 2) result++;
	}
	cout << result << '\n';
}