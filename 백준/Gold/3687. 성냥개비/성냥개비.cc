#include <iostream>
#include <vector>

using namespace std;

int T, n, maxDepth;
int check[6] = { 1, 7, 4, 2, 0, 8 };
vector<int> result;
vector<int> realResult;
long long number = 0;
long long resultNumber = 999999999999999;

void dfs(int level, int remainedMatch) {
    
    if ((maxDepth - level) * 7 < remainedMatch)
        return;
    if (remainedMatch < 0)
        return;
    if (level == maxDepth ) {
        if (!remainedMatch && number < resultNumber) {
            realResult.clear();
            resultNumber = number;
            for (int i = 0;i < maxDepth; i++)
                realResult.push_back(result[i]);
        }
        return;
    }
    if (number >= resultNumber)
        return;

    for (int i = 0;i < 6;i++) {

        if (level == 0 && i == 4) {
            result.push_back(6);
            number = 6;
            dfs(level + 1, remainedMatch - 2 - i);
            number = 0;
            result.pop_back();
            continue;
        }
        number *= 10;
        number += check[i];
        result.push_back(check[i]);
        dfs(level + 1, remainedMatch - i - 2);
        result.pop_back();
        number /= 10;
    }

}

void printSmallNum() {
    result.clear();
    number = 0;
    resultNumber = 999999999999999;

    dfs(0, n);

    for (int i = 0;i < realResult.size(); i++)
        cout << realResult[i];
}

void printBigNum() {
    if (n & 1) {
        cout << '7';
        int cnt = n - 3;
        while (cnt) {
            cout << '1';
            cnt -= 2;
        }
    }
    else {
        for (int i = 0;i < n / 2;i++)
            cout << '1';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> n;
        maxDepth = (n + 6) / 7;
        printSmallNum();
        cout << ' ';
        printBigNum();
        cout << '\n';        
    }
    
    return 0;
}