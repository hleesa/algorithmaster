#include <stdlib.h>
#include <string.h>

int compare(const void* l, const void* r) {
    return *(char*) l - *(char*) r;
}

int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    const int C_MAX = 12;

    char spell_str[C_MAX] = {0,};
    for (size_t i = 0; i < spell_len; ++i) {
        spell_str[i] = spell[i][0];
    }

    qsort(spell_str, spell_len, sizeof(char), compare);
    int ans = 2;

    for (size_t i = 0; i < dic_len; ++i) {
        if (strlen(dic[i]) != spell_len) continue;

        char buf[C_MAX] = {0,};
        strcpy(buf, dic[i]);
        qsort(buf, spell_len, sizeof(char), compare);

        if (strcmp(buf, spell_str) == 0) {
            ans = 1;
            break;
        }
    }

    return ans;
}


int solution2(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    const int C_MAX = 256;
    int s_map[C_MAX] = {0,};전

    for (size_t i = 0; i < spell_len; ++i) {
        ++s_map[spell[i][0]];
    }

    int ans = 2;

    for (size_t i = 0; i < dic_len; ++i) {
        size_t len = strlen(dic[i]);
        if (len != spell_len) continue;

        int dic_map[C_MAX] = {0,};
        for (size_t j = 0; j < len; ++j) {
            ++dic_map[dic[i][j]];
        }

        size_t j;
        for (j = 0; j < C_MAX; ++j) {
            if (dic_map[j] != s_map[j]) break;
        }

        if (j == C_MAX) {
            ans = 1;
            break;
        }
    }

    return ans;
}