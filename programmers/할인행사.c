#include <stdbool.h>
#include <string.h>

#define D_MAX 10

int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[],
             size_t discount_len) {

    int box[11] = {0};

    for (size_t d = 0; d + 1 < D_MAX; ++d) {
        for (size_t w = 0; w < want_len; ++w) {
            if (strcmp(discount[d], want[w]) == 0) {
                ++box[w];
                break;
            }
        }
    }

    int ans = 0;
    for (size_t d = 0; d + D_MAX - 1 < discount_len; ++d) {

        for (size_t w = 0; w < want_len; ++w) {
            if (strcmp(discount[d + D_MAX - 1], want[w]) == 0) {
                ++box[w];
            }
        }

        bool found = true;
        for (size_t b = 0; b < want_len; ++b) {
            if (box[b] < number[b]) {
                found = false;
                break;
            }
        }
        if (found) {
            ++ans;
        }

        for (size_t w = 0; w < want_len; ++w) {
            if (strcmp(discount[d], want[w]) == 0) {
                --box[w];
            }
        }
    }

    return ans;
}