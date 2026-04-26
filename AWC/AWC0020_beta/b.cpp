#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    ll S;
    cin >> S;

    vector<ll> D(N);
    for (ll &d : D) cin >> d;

    vector<ll> heal(N, 0);
    for (int i = 0; i < M; i++) {
        int P;
        ll R;
        cin >> P >> R;
        P--;               
        heal[P] += R;     
    }

    bool tired = false;

    for (int i = 0; i < N; i++) {
        if (!tired) {
            S -= D[i];
            if (S <= 0) tired = true;
        } else {
            S -= 2 * D[i];
        }

        S += heal[i];   
    }

    cout << S << '\n';
    return 0;
}