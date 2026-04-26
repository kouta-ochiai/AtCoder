#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    vector<int> A, B, C;

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == 'A') {A.push_back(i); continue;}
        if (S[i] == 'B') {B.push_back(i); continue;}
        if (S[i] == 'C') {C.push_back(i); continue;}
    }


    int cnt = 0;
    for (int i = 0; i < (int)A.size(); i++){
        for (int j = 0; j < (int)B.size(); j++){
            for (int k = 0; k < (int)C.size(); k++){
                if (B[j] > A[i] && C[k]>B[j]  && B[j]-A[i] == C[k]-B[j]){
                    cnt++; 
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
   
}

