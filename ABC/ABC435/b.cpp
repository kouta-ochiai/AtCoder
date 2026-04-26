#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) cin >> a;

    int ans = 0;

    for (int i = 0; i < N; i++){
        for (int j = i; j< N; j++){
            int l = i, r = j;
            int sum = 0;
            for (int k = l; k <= r; k++) sum += A[k];
            bool ok = true; 
            for (int k = l; k <= r; k++) {
                if (sum % A[k] == 0) {
                    ok = false;
                }
            }
            if (ok) ans++;
        }

    }

    cout << ans << '\n';

   
}

