#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    if (N%2 == 1){
        if ((N/2)+1 >= M){
            cout << "Yes\n"; 
        } else {
            cout << "No\n";
        }
    } else {
        if ((N/2) >= M){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

