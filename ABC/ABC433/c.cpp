#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    vector<pair<int, int>> block; // num, cnt

    for (const char c: S){
        int tmp = c - '0';
        if (!block.empty() && block.back().first == tmp) block.back().second++;
        else block.push_back({tmp, 1}); 
    }

    ll ans = 0;

    for (int i = 0; i+1 < block.size(); i++){
        if (block[i].first + 1 == block[i+1].first) ans += min(block[i].second, block[i+1].second);
    }

    cout << ans << '\n'; 
}

