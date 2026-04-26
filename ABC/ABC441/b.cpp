#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string S, T;
    set<char> U, V;
    cin >> S;
    cin >> T;
    for (char c: S) U.insert(c);
    for (char c: T) V.insert(c);
    int Q;
    cin >> Q;

    while (Q--){
        bool isTakahasi = true, isAoki = true;
        string w;
        cin >> w;
        for (char c: w) {
            if (!U.count(c)) isTakahasi = false;
            if (!V.count(c)) isAoki = false;
        }
        if (isTakahasi && !isAoki) {
            cout << "Takahashi" << '\n'; 
        } else if (!isTakahasi && isAoki) {
            cout << "Aoki" << '\n';
        } else {
            cout << "Unknown" << '\n';
        }
    }

}

