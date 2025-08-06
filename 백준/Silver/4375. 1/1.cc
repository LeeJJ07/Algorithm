#include <iostream>

using namespace std;

int n;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (scanf("%d", &n) != EOF) {
		long long num = 1, res = 1;
		cin >> n;
		while (true) {
			
			if (num % n == 0) {
				cout << res << '\n';
				break;
			}
			else {
				num = (num * 10) + 1;
				num %= n;
				res++;
			}
		}
	}
}