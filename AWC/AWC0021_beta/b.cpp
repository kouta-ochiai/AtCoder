#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> P(M);
    for (int &p: P) cin >> p;

    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        if (K == 0) {cout << 0 << '\n'; continue;}

        pair<int, int> person = {3e5, -1}; // index, score
        while (K--) {
            int C; 
            cin >> C; 
            C--; 
            if (P[C] > person.second) {
                person.first = C;
                person.second = P[C];
            } else if (P[C] == person.second){
                if (C < person.first) {
                    person.first = C;
                }
            }
        }
        cout << ++person.first << '\n';

    }


   
}

