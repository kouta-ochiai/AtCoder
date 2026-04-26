#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if (N>=1 && N<=125){
        cout << '4' << '\n';
    } else if (N<=211){
        cout << '6' << '\n';
    } else {
        cout << '8' << '\n';
    }
   
}

