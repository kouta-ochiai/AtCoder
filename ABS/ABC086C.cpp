#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int st, sx, sy;
    st = 0;
    sx = 0;
    sy = 0;
    while(N--){
        int t, x, y;
        cin >> t >> x >> y;
        int del = t - st;
        int dis = abs(x - sx) + abs(y - sy);
        if (del < dis || (del%2 != dis%2) ){
            cout << "No\n" ;
            return 0;
        } else {
            st = t;
            sx = x;
            sy = y;
        }

    }
    cout << "Yes\n";
   
}

