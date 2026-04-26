#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<char> mp(26);
    for (int i = 0; i < 26; i++){
        mp[i] = char('a' + i);
    }

    for (int i = 0; i < Q; i++){
        char a, b;
        cin >> a >> b;
        char tmp = a;
        for (char &c: mp){
            if (c==tmp) c=b;
        }
    }

    for (int i = 0; i < N; i++){
        for (char c: S[i]){
            cout << mp[c-'a'];
        }
        cout << '\n';
    }

   
}

