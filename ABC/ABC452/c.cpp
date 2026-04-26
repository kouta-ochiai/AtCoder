#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        B[i]--;
    }

    int M;
    cin >> M;
    vector<string> S(M);
    vector<set<char>> pro(N);
    for (int i = 0; i < M; i++){
        cin >> S[i];
        for (int j =0; j < N; j++){
            if (A[j]==(int)S[i].size()){
                pro[j].insert(S[i][B[j]]);
            }
        }
    }
    for (const auto& v: S){
        bool f = true;
        if ((int)v.size()!= N) {
            cout << "No\n";
            continue;
        }
        for (int i = 0; i < N; i++){
            if (!pro[i].count(v[i])){ 
                f = false;
                break;
            }
        }
        if (f) cout << "Yes\n";
        else cout << "No\n";
    }

}

