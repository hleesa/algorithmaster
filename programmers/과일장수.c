#include <stdlib.h>

//v2
int compare2(const void*l, const void* r){
    return *(int*)r - *(int*)l;
}

int solution2(int k, int m, int score[], size_t score_len) {
    qsort(score,score_len, sizeof(int), compare2);
    int ans = 0;
    for(size_t i = 0; i < score_len / m; ++i){
        ans += m * score[i * m + m - 1];
    }
    return ans;
}

//v1
int compare(const void*l , const void* r){
    return *(int*)r - *(int*)l;
}

int solution(int k, int m, int score[], size_t score_len) {
    qsort(score, score_len, sizeof(int), compare);
    int ans = 0;
    size_t i = 0;
    while(i + m < score_len + 1){
        ans += score[i + m - 1] * m;
        i += m;
    }
    return ans;
}