#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    string nS, nT;
    for(char c: S) if(c != 'A') nS += c;
    for(char c: T) if(c != 'A') nT += c;
    if(nS != nT){
        cout << -1 << '\n';
        return 0;
    }
    ll ans = 0;
    int i = 0, j = 0;
    int N = (int)S.size(), M = (int)T.size();
    while(i < N || j < M){
        ll aS = 0, aT = 0;
        while(i < N && S[i]=='A') {aS++; i++;}
        while(j < M && T[j]=='A') {aT++; j++;}
        ans += llabs(aS - aT);
        if (i < N || j < M) {i++; j++;}
    }
    cout << ans << '\n';
    return 0;
}

