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
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    int cnt = 0;

    for (int i = 1; i <= N-2; i++){
        if (A[i-1] < A[i] && A[i] > A[i+1]){
            cnt++;
        }
    }

    cout << cnt << endl;

   
}

