#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    for (int &c: C) cin >> c;

    vector<int> A(N), B(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        if (C[A[i]] >= B[i] ) {ans += B[i]; C[A[i]] -= B[i];}
        else {ans += C[A[i]]; C[A[i]] = 0; } 
    }

    cout << ans << '\n';

}

