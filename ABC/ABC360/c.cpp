#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N+1,0);
    vector<int> W(N+1,0);

    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }
    ll sum = 0;

    for (int i = 1; i <= N; i++){
        cin >> W[i];
        sum += W[i];
    }

    vector<int> m(N+1, 0);
    for (int i = 1; i <= N; i++){
        m[A[i]] = max(m[A[i]], W[i]);
    }
   
    ll sub = 0;
    for (int i = 1; i <= N; i++){
        if(m[i] != 0){
            sub += m[i];
        }
    }

    cout << sum - sub << endl;
}

