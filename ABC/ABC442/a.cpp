#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int cnt = 0;
    for (char c: S){
        if (c == 'i' || c == 'j') cnt++;
    }
   
    cout << cnt << '\n';
}

