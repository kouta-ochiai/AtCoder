#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int s = int(S[0]);
    int e = int(S[S.size()-1]);
    if (s==e){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

