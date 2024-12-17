#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int temp = (n / a) * b;
        answer += temp;
        temp += n % a;

        n = temp;
    }

    return answer;
}