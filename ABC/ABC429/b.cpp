#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int S = 0;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        S += A[i];
    }
    bool f = false;
    for (int i = 0; i < N; i++){
        if ((S - A[i]) == M){
            cout << "Yes" << endl;
            f = true;
            break;
        } 
    }
    if (!f) cout << "No" << endl;
}