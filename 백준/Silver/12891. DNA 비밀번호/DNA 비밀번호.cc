#include <iostream>

using namespace std;

int checkResult = 0;

void Add(char c, int* check, int* my);
void Remove(char c, int* check, int* my);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string A;
	cin >> A;
	int check[4];
	int my[4] = { 0 };

	int result = 0;

	for (int i = 0; i < 4; i++) {
		cin >> check[i];
		if (check[i] == 0)
			checkResult++;
	}
	for (int i = 0; i < M; i++) {
		Add(A[i], check, my);
	}
	if (checkResult == 4) {
		result++;
	}

	for (int i = M; i < N; i++) {
		int j = i - M;
		Add(A[i],check,my);
		Remove(A[j], check, my);
		if (checkResult == 4)
			result++;
	}
	cout << result << "\n";
}

void Add(char c, int* check, int* my) {
	switch (c) {
	case 'A':
		my[0]++;
		if (my[0] == check[0])
			checkResult++;
		break;
	case 'C':
		my[1]++;
		if (my[1] == check[1])
			checkResult++;
		break;
	case 'G':
		my[2]++;
		if (my[2] == check[2])
			checkResult++;
		break;
	case 'T':
		my[3]++;
		if (my[3] == check[3])
			checkResult++;
		break;
	}
}
void Remove(char c, int* check, int* my) {
	switch (c) {
	case 'A':
		if (my[0] == check[0])
			checkResult--;
		my[0]--;
		break;
	case 'C':
		if (my[1] == check[1])
			checkResult--;
		my[1]--;
		break;
	case 'G':
		if (my[2] == check[2])
			checkResult--;
		my[2]--;
		break;
	case 'T':
		if (my[3] == check[3])
			checkResult--;
		my[3]--;
		break;
	}
}