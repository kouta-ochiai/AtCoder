#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < N; i++){
        ll H, L;
        cin >> H >> L;
        pq.push({L,H});
    } 


}

