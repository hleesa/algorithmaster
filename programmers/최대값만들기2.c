#include <stdlib.h>

int compare(const void* l, const void* r) {
    return *(int*) l - *(int*) r;
}

int max(int l, int r) {
    if (l > r)
        return l;
    return r;
}

int solution(int numbers[], size_t numbers_len) {
    qsort(numbers, numbers_len, sizeof(int), compare);

    int ans = max(numbers[0] * numbers[1], numbers[numbers_len - 2] * numbers[numbers_len - 1]);

    return ans;
}