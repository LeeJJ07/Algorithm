#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    int temp;
    if(direction.compare("right")){
        temp = numbers[0];
        for(int i = 1; i<numbers.size();i++){
            numbers[i-1] = numbers[i];
        }
        numbers[numbers.size()-1] = temp;
    } else{
        temp = numbers[numbers.size()-1];
        for(int i = numbers.size()-2;i>=0; i--){
            numbers[i+1] = numbers[i];
        }
        numbers[0] = temp;
    }
    return numbers;
}