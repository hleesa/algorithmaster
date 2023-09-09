#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& ans) {
    for (vector<int>::const_iterator it = ans.begin(); it != ans.end(); ++it)
        cout << *it << " ";
    cout << '\n';
    return;
}

void search(int N, int M, int dep, vector<int>& ans, vector<bool>& vis) {
    if (dep == M) {
        print(ans);
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (vis[i]) continue;
        vis[i] = true;
        ans.push_back(i);
        search(N, M, dep + 1, ans, vis);
        ans.pop_back();
        vis[i] = false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<bool> vis(N + 2);
    vector<int> ans;
    ans.reserve(M);
    search(N, M, 0, ans, vis);
    return 0;
}
