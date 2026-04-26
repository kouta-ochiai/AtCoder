#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if ((a*b)%2) {
        cout << "Odd" << '\n';
    } else {
        cout << "Even" << '\n';
    }

    return 0;
}

