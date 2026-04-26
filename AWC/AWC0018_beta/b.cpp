#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    vector<ll> C(M);
    for (ll &c: C) cin >> c;

    ll total = 0;
    while(N--){
        ll K;
        cin >> K;
        map<int, int> d;
        for (int peaple = 0; peaple < K; peaple++){
            int cls;
            cin >> cls;
            cls--;
            d[cls]++;
        }

        for (auto [cls, num]: d){
            if (C[cls]>=num) total += num;
        }
    }
    cout << total << '\n';
   
}

