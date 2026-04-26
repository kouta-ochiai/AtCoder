#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B;
    cin >> A >> B;
    cout << (A%B==0 ? A/B: (A/B)+1) << '\n';
}

