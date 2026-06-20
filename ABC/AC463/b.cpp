#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    char X;
    bool f = false; 
    
    cin >> N >> X;
    int ind = X - 'A';

    for (int i = 1; i<=N; i++){
        string S;
        cin >> S;
        if (S[ind] == 'o') {
            cout << "Yes\n";
            f = true;
            break;
        }
    }

    if (!f) {
        cout << "No\n";
    }



   
}

