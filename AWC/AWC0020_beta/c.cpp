#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<ll> V(N);
    for (ll &v: V) cin >> v;

    sort(V.begin(), V.end());
    ll ans = 0;

    for (int i = 0; i+1 < N; i++){
        ans += (V[i+1] - V[i]);
    }

    cout << ans << '\n';
   
}

