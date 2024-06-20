#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    int* answer = (int*)malloc((num_list_len - n + 1)*sizeof(int));
    for(int i = n-1; i<num_list_len;i++){
        answer[i - n + 1] = num_list[i];
    }
    return answer;
}