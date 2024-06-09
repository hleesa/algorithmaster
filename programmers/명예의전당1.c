#include <stdio.h>
#include <stdlib.h>

//v2
int compare2(const void* l, const void* r) {
    return *(int*) l - *(int*) r;
}

int* solution2(int k, int score[], size_t score_len) {
    int* ans = (int*) malloc(score_len * sizeof(int));
    int arr[101] = {0};
    if (k > score_len)
        k = score_len;

    for (size_t i = 0; i < k; ++i) {
        arr[i] = score[i];
        qsort(arr, i + 1, sizeof(int), compare2);
        ans[i] = arr[0];
    }

    for (size_t i = k; i < score_len; ++i) {
        if (score[i] > arr[0])
            arr[0] = score[i];
        qsort(arr, k, sizeof(int), compare2);
        ans[i] = arr[0];
    }

    return ans;
}

//v1
int compare(const void* l, const void* r) {
    return *(int*) l - *(int*) r;
}

int* solution(int k, int score[], size_t score_len) {
    int* ans = (int*) calloc(score_len + k, sizeof(int));
    int arr[101] = {0};

    for (size_t i = 0; i < k; ++i) {
        arr[i] = score[i];
        qsort(arr, i + 1, sizeof(int), compare);
        ans[i] = arr[0];
    }

    for (size_t i = k; i < score_len; ++i) {
        if (score[i] > arr[0])
            arr[0] = score[i];
        qsort(arr, k, sizeof(int), compare);
        ans[i] = arr[0];
    }

    return ans;
}

/*
 * k > score_len
 */