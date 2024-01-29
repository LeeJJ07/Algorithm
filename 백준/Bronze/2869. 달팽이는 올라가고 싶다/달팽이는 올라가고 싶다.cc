#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long A, B, V;
	cin >> A >> B >> V;
	long result = 1;

	if (V > A) {
		V -= A;
		result += (V / (A - B));
		if (V % (A - B) != 0) {
			result++;
		}
	}

	cout << result << "\n";
}