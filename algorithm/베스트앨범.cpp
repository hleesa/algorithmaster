#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

map<string, vector<pair<int, int>>> getGenreToPlaysAndId(const vector<string>& genres, const vector<int>& plays) {
    map<string, vector<pair<int, int>>> genreToPlaysAndId;

    for (int i = 0; i < genres.size(); ++i) {
        genreToPlaysAndId[genres[i]].emplace_back(plays[i], i);
    }

    for (auto& [genre, playsAndIds]: genreToPlaysAndId) {
        sort(playsAndIds.begin(), playsAndIds.end(),
             [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                 return lhs.first > rhs.first;
             });
    }

    return genreToPlaysAndId;
}

vector<string> getGenresOrder(const map<string, vector<pair<int, int>>>& genreToPlaysAndId) {
    map<string, int> genreToPlays;

    for (const auto& [genre, playsAndIds]: genreToPlaysAndId) {
        for (const auto& playAndId: playsAndIds)
            genreToPlays[genre] += playAndId.first;
    }

    priority_queue<pair<int, string >> pq;
    for (const auto& [genre, totalPlays]: genreToPlays) {
        pq.emplace(totalPlays, genre);
    }

    vector<string> sortedGenre;
    sortedGenre.reserve(genreToPlays.size());

    while (!pq.empty()) {
        sortedGenre.push_back(pq.top().second);
        pq.pop();
    }

    return sortedGenre;
}

vector<int> getIndexInGenre(const map<string, vector<pair<int, int>>>& genreToPlaysAndId, const string& genre) {
    const auto& playIdx = genreToPlaysAndId.at(genre);
    vector<int> idx;
    idx.reserve(2);

    for (int i = 0; i < min((int) playIdx.size(), 2); ++i) {
        idx.push_back(playIdx[i].second);
    }

    return idx;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<pair<int, int>>> genreToPlaysAndId = getGenreToPlaysAndId(genres, plays);
    vector<string> sortedGenre = getGenresOrder(genreToPlaysAndId);
    vector<int> ans;
    ans.reserve(sortedGenre.size() * 2);

    for (const auto& genre: sortedGenre) {
        vector<int> idx = getIndexInGenre(genreToPlaysAndId, genre);
        ans.insert(ans.end(), idx.begin(), idx.end());
    }

    return ans;
}
