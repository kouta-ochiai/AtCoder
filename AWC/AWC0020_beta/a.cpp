#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++){
        ll A;
        cin >> A;
        ans += (A%N);
    }

    cout << (ans%N == 0 ? "Yes\n" : "No\n");
   
}

