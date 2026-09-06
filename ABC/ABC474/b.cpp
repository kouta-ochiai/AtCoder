#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int t;
    cin >> N;
    bool ans = true;

    t = N/10;
    for (int i = 0; i < t; i++){
        int chk = 55+(100*i);
        int sum = 0;
        for (int j = 0; j < 10; j++){
            int x;
            cin >> x;
            sum += x;
        }
        if (sum!=chk){
            cout << "No" << endl;
            ans = false;
            break;
        }
    }
    while (t--){

    }

    if (ans) {
        cout << "Yes" << endl;
    }

   
}

