#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> P(N), C(N);
    vector<vector<int>> F(N);
    for (int i = 0; i < N; i++){
        cin >> P[i] >> C[i];
        F[i].resize(C[i]);
        for (int j = 0; j < C[i]; j++) cin >> F[i][j];
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            bool jud = true;
            if (P[i]>=P[j]){
                set<int> is;
                set<int> js;
                for (auto s: F[i]) is.insert(s);
                for (auto s: F[j]) js.insert(s);
                for (auto s: is) if(!js.count(s))  jud = false;

                if (jud && (P[i]>P[j] || js.size() > is.size())){
                    cout << "Yes" << '\n';
                    return 0;
                }   
            }

        }
    }

    cout << "No" << '\n';
    return 0; 
   
}

