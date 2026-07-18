#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    ll ma, mb;
    ma = LLONG_MIN;
    mb = LLONG_MIN;
    for (int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        ma = max(ma, tmp);
    }

    for (int j = 0; j < N; j++){
        ll tmp;
        cin >> tmp;
        mb = max(mb, tmp);
    }

    cout << ma+mb << endl;
   
}

