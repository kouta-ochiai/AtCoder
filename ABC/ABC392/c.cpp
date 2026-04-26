#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N+1), Q(N+1);
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) cin >> Q[i];
    vector<int> rev(N+1);
    for (int i = 1; i <= N; i++){
        rev[Q[i]] = i;
    }
    for (int i = 1; i <= N; i++) cout << Q[P[rev[i]]] << " ";
    cout << endl;
}