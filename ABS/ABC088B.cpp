#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) cin >> a;
    sort(A.begin(), A.end());
    int alice = 0;
    int bob = 0;
    while(!A.empty()){
        auto ae = A.back();
        alice += ae;
        A.pop_back();
        if (A.empty()) break;
        auto be = A.back();
        bob += be;
        A.pop_back();
    }
    cout << abs(alice - bob) << '\n';
}

