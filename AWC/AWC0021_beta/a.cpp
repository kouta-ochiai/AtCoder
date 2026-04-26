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

    while (N--){
        int A;
        cin >> A;
        vector<int> B(A);
        for (int &b: B) {cin >> b; if (b >= K) ans++;}
    }

    cout << ans << '\n';
   
}

