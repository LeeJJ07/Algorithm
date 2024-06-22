#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    while(age>0){
        answer = (char)((age%10) + 'a') + answer;
        age/=10;
    }
    return answer;
}