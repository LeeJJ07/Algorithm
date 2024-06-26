#include <string>
#include <vector>

using namespace std;

bool isNotPrime(int num){
    for(int i = 2; i*i<=num; i++){
        if(!(num % i))
            return true;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    for(int i = 2;i<=n;i++)
        if(isNotPrime(i)) answer++;
    return answer;
}