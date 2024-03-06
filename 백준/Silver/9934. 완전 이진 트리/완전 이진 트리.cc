#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<int> a;
vector<int> visited;
int N, num;

void BFS() {
	queue<int> q;
	q.push(num / 2);
	visited[num / 2] = 1;
	int minus = (num + 1) / 4;
	while (q.size()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int now = q.front();
			cout << a[now] << ' ';
			q.pop();
			for (int next : {now - minus, now + minus}) {
				if (next >= num)continue;
				if (visited[next])continue;
				visited[next] = 1;
				q.push(next);
			}
		}
		minus /= 2;
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	num = pow(2, N) - 1;
	a.resize(num);
	visited.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	BFS();
}