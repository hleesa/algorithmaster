/*

그래프의 간선 정보가 주어진다.

생성한 정점의 번호와,
정점을 생성하기 전 도넛, 막대, 8자 모양 그래프이 수를 구한다.

*/

#include <vector>
#include <queue>

using namespace std;

const int MX = 1000002;
vector<int> adj[MX];
int inOrder[MX];
int outOrder[MX];
bool vis[MX];

int findDot(){
    for(int i=1; i +1 <MX; ++i){
        if(inOrder[i] == 0 && outOrder[i] == 0) continue;
        if(inOrder[i] == 0 && outOrder[i] > 1)
            return i;
    }
    return -1;
}

vector<int> search(int vtx){
    vector<int> ret;
    ret.push_back(vtx);
    queue<int> q;
    q.push(vtx);
    vis[vtx] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : adj[cur]){
            if(vis[next]) continue;
            vis[next] = true;
            q.push(next);
            ret.push_back(next);
        }
    }
    return ret;
}

// 도넛 1, 막대 2, 8자 3
int getType(const vector<int>& graph){
    int n = graph.size();
    int out = 0;
    for(int i=0; i<n; ++i){
        out += outOrder[graph[i]];
    }
    if(out == n){
        return 1;
    }
    else if(out == n -1){
        return 2;
    }
    else if(out == n+1){
        return 3;
    }
    return 4;
}

vector<int> countAns(){
    vector<int> ans(4);
    int dot = findDot();
    ans.front() = dot;
    vis[dot] = true;
    for(int next : adj[dot]){
        vector<int> graph = search(next);
        ++ans[getType(graph)];
    }
    return ans;
}

void getAdj(const vector<vector<int>>& edges){
    for(int i=0; i<edges.size(); ++i){
        int from = edges[i].front();
        int back = edges[i].back();
        adj[from].push_back(back);
        ++outOrder[from];
        ++inOrder[back];
    }
}

vector<int> solution(vector<vector<int>> edges) {
    getAdj(edges);
    return countAns();
}

/*
 * 버그를 바로 찾지 못함. 시간 오래 걸림.
 * 문제의 조건을 다 사용하지 않았다. [도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 수의 합은 2이상입니다.]
 */