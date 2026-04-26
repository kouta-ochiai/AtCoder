#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P, Q, X, Y;
    cin >> P >> Q;
    cin >> X >> Y;
    cout << ((P <= X && X < P+100 && Q <= Y && Y < Q+100)? "Yes\n" : "No\n");
}

