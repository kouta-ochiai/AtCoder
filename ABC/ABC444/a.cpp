#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    cin >> N;
    bool f = true;
    int tmp;
    tmp = N[0];
    for (char c: N){
        if (c != tmp){
            f = false;
            break;
        }
    }
    if (f){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

   
}

