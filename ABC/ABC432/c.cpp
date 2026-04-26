#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    ll X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    ll A0 = A[0];
    ll low = 0, high = A0;
    ll sum_base = 0;

    for (int i = 0; i < N; i++) {
        ll num = (A0 - A[i]) * X;
        if (num % (Y - X) != 0) { 
            cout << -1 << endl; 
            return 0; 
        }
        ll base = num / (Y - X);
        low = max(low, -base);
        high = min(high, A[i] - base);
        sum_base += base;
    }

    if (low > high) {
        cout << -1 << endl;
        return 0;
    }

    ll b0 = high; 
    ll ans = b0 * N + sum_base;
    cout << ans << endl;
}
