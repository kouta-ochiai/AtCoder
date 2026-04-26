#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    int m = 1e9;
    for (int a: A){
        cin >> a;
        if (a%2 == 1){
            cout << 0 << '\n';
            return 0;
        }
        int count = 0;
        while (a > 0 && a%2==0){
            a /= 2;
            count++;
        }
        m = min(m, count);
    }
    cout << m << '\n';
    return 0;
}

