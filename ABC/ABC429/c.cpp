#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    unordered_map<long long, long long> cnt;
    cnt.reserve(N*2);
    for (int i = 0; i < N; i++){
        long long a;
        cin >> a;
        cnt[a]++;
    }

    long long ans = 0;
    for (auto &[val, c]: cnt){
        if (c >= 2) {
            ans += c * (c - 1) * (N - c) /2;
        }
    }
    cout << ans << endl;

}