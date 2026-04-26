#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; i++){
        int tmp = 0;
        string num = to_string(i);
        for (char s: num){
            tmp += s - '0';
        }
        if (A <= tmp && tmp <= B){
            sum += i;
        }
    }
    cout << sum << '\n';
    return 0;
   
}

