#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        --A[i]; // 0-index
    }

    vector<int> dp(N, -1); // dp[v] = v から辿った先の固定点

    for (int i = 0; i < N; i++) {
        if (dp[i] != -1) {
            cout << dp[i] + 1 << " ";
            continue;
        }

        int ind = i;
        vector<int> path;

        // 未確定の間だけ進む
        while (dp[ind] == -1) {
            path.push_back(ind);
            if (A[ind] == ind) {   // 固定点
                dp[ind] = ind;
                break;
            }
            ind = A[ind];
        }

        int ans = dp[ind];          // 答え確定
        for (int u : path) dp[u] = ans;

        cout << ans + 1 << " ";
    }
    cout << endl;
}
