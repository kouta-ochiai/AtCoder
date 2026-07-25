#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    cin >> N;

    bool f = true;

    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if (tmp >= 0) {
            f = false;
        }
    }

    if (f) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl;
    }
   
}

