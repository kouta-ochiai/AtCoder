#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> visit;
    while (N--){
        ll C, M;
        cin >> C >> M;
        vector<ll> P(M);
        ll sum = 0;
        for (ll &p :P) {
            cin >> p;
            sum += p; 
        }
        visit.push_back(max(sum-C, 0LL));
    }
    sort(visit.rbegin(), visit.rend());
    for (int i = 0 ; i < K; i++) ans += visit[i];

    cout << ans << '\n';
}

