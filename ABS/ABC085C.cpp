#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N , Y;
    cin >> N >> Y;
    for (int a = 0; a <= N; a++){
        for (int b = 0; b <= N-a; b++){
            int c = N - a - b;
            int sum = 10000*a + 5000*b + 1000*c;
            if (sum == Y){
                cout << a << " " << b << " " << c << '\n';
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << '\n';
    return 0;
   
}

