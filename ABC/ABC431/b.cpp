#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, N;
    cin >> X;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    vector<bool> J(N, false);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int P;
        cin >> P;
        P--;
        if (J[P] == false) {
            J[P] = true;
            X += W[P];
        } else {
            J[P] = false;
            X -= W[P];
        }
        cout << X << endl;
    }

}