#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> P(N,0), Q(N,0);
    int cntl = 1;
    int cntu = 1;

    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        P[i] = tmp;
    }

    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        Q[i] = tmp;
    }

    for (int i = 0; i < N; i++){
        int min = i;
        for(int j = i + 1; j < N; j++){
            if(P[min] > P[j]){
                int number = P[i];
                P[i] = P[j];
                P[j] = number;
                cntl++;
            }
        }

    }

    for (int i = 0; i < N; i++){
        cout << P[i];
    }
    cout << endl;

    cout << cntl << endl;
   
}

