#include <iostream>
#include <climits>
using namespace std;

void DFS(int num, int count);
static int result = INT_MAX;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int X;
	cin >> X;
	
	int count = 0;
	DFS(X, count);

	cout << result << "\n";
}
void DFS(int num, int count) {
	if (result < count)
		return;

	while (num != 1) {
		if (result < count)
			break;
		if (num % 3 == 0)
			DFS(num / 3, count + 1);
		
		if (num % 2 == 0)
			DFS(num/2, count + 1);
		num--;
		count++;
	}
	if (result > count)
		result = count;
}