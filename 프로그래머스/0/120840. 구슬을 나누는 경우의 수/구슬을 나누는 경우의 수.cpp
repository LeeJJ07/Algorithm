#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    //5 4
    //2 1
    for(int i = 1; i <= balls - share; i++){
        answer *= balls - i + 1;
        answer /= i;
    }
    return answer;
}