#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int count = 0;
    for (char s: S){
        if (s == '1') count++;
    }
    cout << count << '\n';
    return 0;
}

