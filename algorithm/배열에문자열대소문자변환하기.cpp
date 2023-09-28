#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int (*convertFunc(int i))(int){
    return i%2 == 1 ? ::toupper : ::tolower;
}

vector<string> solution(vector<string> strArr) {
    for(size_t i = 0; i< strArr.size(); ++i){
        transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), convertFunc(i));
    }
    return strArr;
}