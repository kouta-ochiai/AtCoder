#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, D;
    cin >> M >> D;
    string S;
    cin >> S;
    vector<bool> ptn(M,false);
    int ans = 0;
    for (int i = 0; i < M; i++){
        if (S[i] == 'G'){
            for (int j = 0; j <= D; j++){
                    if (i-j >= 0){
                        ptn[i-j] = true; 
                    }
                    if (i+j < M){
                        ptn[i+j] = true;
                    }
                }
        }
    }


    for (int i = 0; i < M; i++){
        if (!ptn[i]) ans++;
    }

    cout << ans << endl;
   
}

