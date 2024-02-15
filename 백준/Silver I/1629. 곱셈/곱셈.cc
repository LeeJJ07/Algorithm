#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A, B, C;
	cin >> A >> B >> C;

	vector<long> re;
	while (B > 1) {
		if (B % 2 == 1) {
			re.push_back(A % C);
		}
		long num = ((A % C) * (A % C)) % C;
		A = num;
		B /= 2;
	}
	for (long number : re) {
		A = (A * number) % C;
	}
	cout << A%C << '\n';
}