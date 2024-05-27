#include <iostream>
#include <vector>

using namespace std;

int N, M;
const int MX = 102;
int swtch[MX];
vector<int> op[MX];

void input()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> swtch[i];
    }
    cin >> M;
    for(int i =0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        op[i].push_back(a);
        op[i].push_back(b);
    }
}

void print(){
    for (int i = 1; i <= N ; ++i) {
        cout << swtch[i - 1];
        if (i % 20 == 0) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
}

void man(int num){
    for (int i = num - 1; i < N; i += num) {
        swtch[i] = !swtch[i];
    }
}

void woman(int num){
    int l = num - 1, r = num + 1;
    while(0 <= l && r < N && (swtch[l] == swtch[r])){
            --l;
            ++r;
    }
    swtch[num] = !swtch[num];
    for (int i = 1; i < r - num; ++i) {
        swtch[num + i] = !swtch[num + i];
        swtch[num - i] = !swtch[num - i];
    }
}

void doOp(){
    for(int i=0; i<M; ++i){
        if(op[i].front() == 1) {
            man(op[i].back());
        } else {
            woman(op[i].back() - 1);
        }
    }
}

int main(){
    input();
    doOp();
    print();
}

/*
 * 문제를 제대로 읽지 않음.
 * 스위치 번호 1-base != 배열의 인덱스 0-base
 * 스위치 20개씩 개행해서 출력
 */