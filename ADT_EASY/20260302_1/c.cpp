#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S;
    cin >> T;
    if (S==T) {cout << '0' << '\n'; return 0;}
    for (int i = 0; i < (int)min(S.size(), T.size()); i++){
        if (S[i] != T[i]) {cout << i+1 << '\n'; return 0;}
    }
    cout << (int)min(S.size(), T.size())+1 << '\n';
}

