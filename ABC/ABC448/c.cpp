#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    vector<pair<int, int>> C(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[i] = {A[i], i};
    }

    sort(C.begin(), C.end());

    while (Q--) {
        int K;
        cin >> K;

        set<int> removed;
        for (int i = 0; i < K; i++) {
            int b;
            cin >> b;
            b--;
            removed.insert(b);
        }

        int ans = -1;
        for (int i = 0; i <= K; i++) {
            if (!removed.count(C[i].second)) {
                ans = C[i].first;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}