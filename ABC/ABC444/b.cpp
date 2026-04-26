#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int count = 0;

    for (int i = 1; i <=N; i++){
        string s = to_string(i);
        int sum = 0;
        for (char c: s){
            sum += c - '0';
        }
        if (sum == K){
            count++;
        }
    }
    cout << count << endl;

}

