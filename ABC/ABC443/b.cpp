#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    ll sum = 0;
    ll cnt = -1;
    while(sum<K){
        sum += N;
        N++;
        cnt++;
    }
    cout << cnt << '\n'; 
   
}

