#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string f(ll N){
    if (N == 0) return "0";
    string s;
    while (N > 0){
        int r = N % 5;
        s += char('0' + 2*r); 
        N /= 5;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ll N;
    cin >> N;
    N--;              
    cout << f(N) << "\n";
}