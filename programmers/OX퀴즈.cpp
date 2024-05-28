#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> ans;
    ans.reserve(quiz.size());
    string candi[2] = {"O", "X"};

    for (const auto &q: quiz) {
        stringstream ss(q);
        int x, y;
        char op, eq;
        string z;

        ss >> x >> op >> y >> eq >> z;

        int sign = op == '+' ? 1 : -1;
        int result = 1;

        if (x + sign * y == stoi(z)) {
            result = 0;
        }
        ans.push_back(candi[result]);
    }

    return ans;
}

/*
 * ss >> x >> op >> y >> eq >> z;
 * (ss >> x; ss >> op; ss >> y; ss >> eq; ss >> z;)
 */