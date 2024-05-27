#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

long dateToDay(string date) {
    stringstream ss(date);
    long year, month, day;
    char delim;
    ss >> year >> delim >> month >> delim >> day;
    return year * 28 * 12 + month * 28 + day;
}

map<string ,long> getTermToMonth(const vector<string>& terms){
    map<string, long> ret;
    for (vector<string>::const_iterator it = terms.begin(); it != terms.end(); ++it) {
        size_t alphaEnd = it->find(" ");
        string alpha = it->substr(0, alphaEnd);
        string monthStr = it->substr(alphaEnd + 1);
        stringstream ss(monthStr);
        long month;
        ss >> month;
        ret.insert(pair<string, long>(alpha, month));
    }
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    long lastDay = dateToDay(today);
    map<string, long> termToMonth = getTermToMonth(terms);
    for (size_t i = 0; i < privacies.size(); ++i) {
        string privacy = privacies[i];
        size_t dateEnd = privacy.find(" ");
        string date = privacy.substr(0, dateEnd);
        string term = privacy.substr(dateEnd + 1);
        long expireDay = dateToDay(date) + termToMonth.at(term) * 28;
        if (expireDay <= lastDay)
            answer.push_back(i + 1);
    }
    return answer;
}
