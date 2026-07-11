#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    bool f = false;
    for (int i= 1; i <= 1000; i++){
        if (a%16 == b%9){
            f = true;
            break;

        } 
    }

    if (f){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
   
}

