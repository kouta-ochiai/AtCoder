#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> ans(M, 0);
    for (int i = 0; i < N; i++){
        int C, S;
        cin >> C >> S;
        C--;
        ans[C] = max(S, ans[C]);
    }

    for (int i = 0; i < M; i++){
        if (ans[i]==0){
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
   
}

