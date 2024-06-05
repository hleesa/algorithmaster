#include <stdlib.h>

/*
 * v2
 */

int base;

int compare(const void *l, const void *r) {
    int l_val = *(int *) l;
    int r_val = *(int *) r;
    int l_diff = abs(l_val - base);
    int r_diff = abs(r_val - base);

    if (l_diff == r_diff) {
        return r_val - l_val;
    }
    return l_diff - r_diff;
}

int *solution(int numlist[], size_t numlist_len, int n) {
    base = n;
    qsort(numlist, numlist_len, sizeof(int), compare);

    int *ans = (int *) malloc(numlist_len * sizeof(int));
    for (size_t i = 0; i < numlist_len; ++i) {
        ans[i] = numlist[i];
    }

    return ans;
}


/*
 * v1
 */

//int compare(const void *l, const void *r) {
//    return (*(int *) r) - (*(int *) l);
//}
//
//int *solution(int numlist[], size_t numlist_len, int n) {
//    qsort(numlist, numlist_len, sizeof(int), compare);
//    size_t mid = 0;
//    for (size_t i = 0; i < numlist_len; ++i) {
//        if (abs(numlist[i] - n) < abs(numlist[mid] - n)) {
//            mid = i;
//        }
//    }
//
//    int *ans = (int *) malloc(numlist_len * sizeof(int));
//    int a_size = 0;
//    ans[a_size++] = numlist[mid];
//
//    int l = mid - 1, r = mid + 1;
//    while (l >= 0 && r < numlist_len) {
//        if (abs(numlist[l] - n) <= abs(numlist[r] - n)) {
//            ans[a_size++] = numlist[l];
//            --l;
//        } else if (abs(numlist[r] - n) < abs(numlist[l] - n)) {
//            ans[a_size++] = numlist[r];
//            ++r;
//        }
//    }
//    while (l >= 0) {
//        ans[a_size++] = numlist[l];
//        --l;
//    }
//    while (r < numlist_len) {
//        ans[a_size++] = numlist[r];
//        ++r;
//    }
//
//    return ans;
//}
