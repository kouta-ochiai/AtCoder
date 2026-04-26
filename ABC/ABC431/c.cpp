#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> H(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());
    bool f = true;
    // 交換不等式によりこれで必要十分になる(最も危険な場合を調べてることに相当)
    for (int i = 0; i < K; i++){
        if (H[i] > B[M-K+i]){
            f = false;
            break;
        }
    }
    if (f) {cout << "Yes" << endl;}
    else {cout << "No" << endl;}

}