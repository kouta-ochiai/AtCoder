#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    ll ans = 0;
    ll sub = 0;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
        ans += A[i];
        sub += A[i]*A[i];
    }

    cout << (ans*ans - sub)/2 << endl;
   
}

