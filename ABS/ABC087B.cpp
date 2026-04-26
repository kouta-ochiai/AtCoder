#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int count = 0;
    for (int i = 0; i <= A; i++){
        for (int j = 0; j <= B; j++){
            for (int k = 0; k <= C; k++){
                if (i*500 + j *100 + k*50 == X) count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
   
}

