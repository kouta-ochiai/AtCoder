#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> St(M, 0);
    for (int i = 0; i < N; i++){
        int Li;
        cin >> Li;
        vector<int> X(Li);
        bool f = false;
        for (int l = 0; l < Li; l++){
            cin >> X[l];
            if (St[X[l]] != -1 && !f){
                cout << X[l] << endl;
                St[X[l]] = -1;
                f = true;
            }
        }
        if (!f) cout << 0 << endl;

    }
}

