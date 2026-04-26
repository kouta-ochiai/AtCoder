#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H, vector<int> (W));
    for (auto &row: A) for (auto &val: row) cin >> val ;

    set<int> B;
    while(N--){
        int tmp;
        cin >> tmp;
        B.insert(tmp);
    }

    int ans = 0;
    for (const auto &row: A){
        int cnt = 0;
        for (const auto &val: row){
            cnt += B.count(val);
        }
        ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
}

