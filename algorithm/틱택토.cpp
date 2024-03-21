#include <iostream>
#include <string>
#include <map>

using namespace std;
const int YMAX = 3;
const int XMAX = 3;
const char X = 'X';
const char O = 'O';
const char DOT = '.';

char rowEnd(const string &str, int idx) {
    for (int x = 1; x < XMAX; ++x) {
        if (str[idx] != str[idx + x]) {
            return 'n';
        }
    }
    if (str[idx] != DOT) {
        return str[idx];
    }
    return 'n';
}

char colEnd(const string &str, int idx) {
    for (int y = 1; y < YMAX; ++y) {
        if (str[idx] != str[y * YMAX + idx]) {
            return 'n';
        }
    }
    if (str[idx] != DOT) {
        return str[idx];
    }
    return 'n';
}

char digUpEnd(const string &str, int idx) {
    for (int x = 0; x < YMAX; ++x) {
        if (str[idx] != str[YMAX * (YMAX - (x + 1)) + x]) {
            return 'n';
        }
    }
    if (str[idx] != DOT) {
        return str[idx];
    }
    return 'n';
}

char digDownEnd(const string &str, int idx) {
    for (int x = 0; x < YMAX; ++x) {
        if (str[idx] != str[YMAX * x + x]) {
            return 'n';
        }
    }
    if (str[idx] != DOT) {
        return str[idx];
    }
    return 'n';
}

map<char, int> getEndInfo(const string &str) {
    map<char, int> winToNum;
    for (int y = 0; y < YMAX * XMAX; y += YMAX) {
        ++winToNum[rowEnd(str, y)];
    }
    for (int x = 0; x < XMAX; ++x) {
        ++winToNum[colEnd(str, x)];
    }
    ++winToNum[digUpEnd(str, 2)];
    ++winToNum[digDownEnd(str, 0)];
    return winToNum;
}

map<char, int> count(const string &str) {
    map<char, int> charToNum;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == O) {
            ++charToNum[O];
        } else if (str[i] == X) {
            ++charToNum[X];
        } else {
            ++charToNum[DOT];
        }
    }
    return charToNum;
}

bool valid(const string &str) {
    map<char, int> winToNum = getEndInfo(str);
    map<char, int> charToNum = count(str);
    if (!(charToNum[X] == charToNum[O] || charToNum[X] == charToNum[O] + 1)) {
        return false;
    } else if (0 < winToNum[X] && winToNum[X] < 3 && winToNum[O] == 0) {
        if (charToNum[X] != charToNum[O] + 1)
            return false;
    } else if (winToNum[O] == 1 && winToNum[X] == 0) {
        if (charToNum[X] != charToNum[O]) {
            return false;
        }
    } else if (winToNum[X] > 0 && winToNum[O] > 0) {
        return false;
    } else if (winToNum[X] == 0 && winToNum[O] == 0) {
        if (charToNum[DOT] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "end") {
            break;
        }
        string ans = valid(str) ? "valid" : "invalid";
        cout << ans << '\n';
    }
}

/*
 * 구현에 시간 많이 걸림.
 * 올바른 게임의 조건 전부 찾지 못함.
 * 1~2 가지 조건만 더 찾으면 되는데, 찾아야 할 조건이 훨씬 많다고 생각하고 포기함.
 */