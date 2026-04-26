#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int len = N - (int)S.size();

    for (int i = 0; i < len; i++){
        cout << 'o';
    }
    cout << S << '\n';
}

