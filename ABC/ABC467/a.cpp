#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    float H, W, ans;
    cin >> H >> W;
    H = 0.01*H;
    ans = W/H/H;
    if (ans >=25){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
   
}

