#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    bool f = false;
    int vol = 0;
    while(Q--){
        int A;
        cin >> A;
        if (A == 1) vol++;
        if (A == 2) if (vol >= 1) vol--;
        if (A == 3) f = !f;

        cout << (f && vol >= 3 ? "Yes\n" : "No\n" );
    }

}

