#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
    
    int* answer = NULL;
    int a = slicer[0], b = slicer[1], c = slicer[2], i;
    if(n==1){
        answer = (int*)malloc((b+1)*sizeof(int));
        for(i = 0;i<=b;i++){
            answer[i] = num_list[i];
        }
    }else if(n==2){
        answer = (int*)malloc((num_list_len - a + 1)*sizeof(int));
        for(i = a;i<num_list_len;i++){
            answer[i - a] = num_list[i];
        }
    }else if(n==3){
        answer = (int*)malloc((b - a + 1)*sizeof(int));
        for(i = a;i<=b;i++){
            answer[i-a] = num_list[i];
        }
    }else if(n==4){
        answer = (int*)malloc(((b - a) / c + 1) * sizeof(int));
        for(i = a;i<=b;i+=c){
            answer[(i-a)/c] = num_list[i];
        }
    }
    return answer;
}