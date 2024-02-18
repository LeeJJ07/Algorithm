#include <iostream>
#include <vector>
using namespace std;

int ruleDNA[4];
int myDNA[4];

void add(char c) {
	switch (c) {
	case 'A':
		myDNA[0]++;
		break;
	case 'C':
		myDNA[1]++;
		break; 
	case 'G':
		myDNA[2]++;
		break;
	case 'T':
		myDNA[3]++;
		break;
	}
}
void sub(char c) {
	switch (c) {
	case 'A':
		myDNA[0]--;
		break;
	case 'C':
		myDNA[1]--;
		break;
	case 'G':
		myDNA[2]--;
		break;
	case 'T':
		myDNA[3]--;
		break;
	}
}

bool check() {
	for (int i = 0; i < 4; i++) {
		if (ruleDNA[i] > myDNA[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	string dna;
	cin >> dna;
	for (int i = 0; i < 4; i++) {
		cin >> ruleDNA[i];
	}
	for (int i = 0; i < P; i++) {
		add(dna[i]);
	}
	int result = 0;
	if (check())result++;

	for (int i = P; i < S; i++) {
		sub(dna[i - P]);
		add(dna[i]);
		if (check())result++;
	}
	cout << result << '\n';
}