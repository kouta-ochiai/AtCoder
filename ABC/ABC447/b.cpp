#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    vector<int> cnt(26, 0);

    for (char s: S) cnt[s-'a']++;

    int max = *max_element(cnt.begin(), cnt.end());

    for (char s: S) {
        if (cnt[s-'a']!=max) cout << s;
    } 
    cout << '\n';
}

