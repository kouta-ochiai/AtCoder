#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N+1);
    for (int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        P[tmp] = i;
    }
    sort(P.begin(), P.end());

    while (Q--){
        int aq;
        cin >> aq;
        auto it = find(P.begin(), P.end(), aq);
        int idx = distance(P.begin(), it);
        P[idx]=N;
        ++idx;
        while(idx <= N){
            P[idx]--;
            idx++;
        }
    }

    sort(P.begin(), P.end());
    for (int i = 1; i<= N; i++){
        cout << P[i];
    }
    cout << endl;
   
}

