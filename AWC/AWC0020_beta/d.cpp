#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll L;
    cin >> N >> L;

    vector<pair<ll,ll>> seg;

    for(int i=0;i<N;i++){
        ll x,r;
        cin >> x >> r;

        ll l = max(0LL, x-r);
        ll rr = min(L, x+r);

        seg.push_back({l,rr});
    }

    sort(seg.begin(), seg.end());

    ll cur = 0;

    for(auto [l,r] : seg){
        if(l > cur){
            cout << "No\n";
            return 0;
        }
        cur = max(cur,r);
        if(cur >= L){
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}