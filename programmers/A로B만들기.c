#include <string.h>

#define LO_MAX 26

int solution(const char* before, const char* after) {
    int be_charset[LO_MAX] = {0};
    int af_charset[LO_MAX] = {0};
    size_t len = strlen(before);

    for (size_t i = 0; i < len; ++i) {
        ++be_charset[before[i] - 'a'];
        ++af_charset[after[i] - 'a'];
    }
    for (size_t i = 0; i < LO_MAX; ++i) {
        if (be_charset[i] != af_charset[i])
            return 0;
    }

    return 1;
}

/*
 * 문제 정확히 이해하기
 */