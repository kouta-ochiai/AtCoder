#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll T;
    cin >> N >> T;

    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int i = 0;
    ll t = 0, ans = 0;
    bool open = true;
    ll reopen = (ll)4e18; // 次に必ず開く時刻（閉じてない間は無効）

    while (t < T) {
        ll nextA = (i < N ? v[i] : (ll)4e18);

        if (open) {
            ll nxt = min(nextA, T);
            ans += (nxt - t);
            t = nxt;
            if (t == T) break;

            // 青木が来たので即閉じる
            i++;
            open = false;
            reopen = t + 100;   // ★ここで固定
        } else {
            ll nxt = min({reopen, nextA, T});
            t = nxt;
            if (t == T) break;

            if (t == reopen) {
                open = true;
                reopen = (ll)4e18;
            } else {
                // 閉じてる間の青木は無視（ただし時刻は進んでいる）
                i++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}