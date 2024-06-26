#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, number = 1;
    while(number<=n){
        answer++;
        number *= answer;
    }
    return answer - 1;
}