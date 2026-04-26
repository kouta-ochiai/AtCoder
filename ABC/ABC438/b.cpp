#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int ans = INT_MAX;
    for (int i = 0; i + M <= N; i++) {
        int cnt = 0;
        for (int k = 0; k < M; k++) {
            int tar = S[i + k] - '0';
            int tmp = T[k] - '0';
            cnt += (tar - tmp + 10) % 10;
        }
        ans = min(ans, cnt);
    }

    cout << ans << '\n';
}