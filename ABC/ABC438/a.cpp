#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D, F;
    cin >> D >> F;
    cout << (F-(D%7) > 0? F-(D%7): F-(D%7)+7 )<< '\n';
}

