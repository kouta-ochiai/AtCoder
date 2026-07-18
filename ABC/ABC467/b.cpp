#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int ans = 0;
    while(N--){
        int A, B;
        string S;
        cin >> A >> B >> S;
        if (S == "keep"){
            ans += B-A;
        }
    }

    cout << ans << endl;
   
}

