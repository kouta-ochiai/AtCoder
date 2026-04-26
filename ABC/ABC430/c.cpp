#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    ll ans = 0;
    int ra = 0, rb = 0;
    int cnta1 = 0, cntb1 = 0; // [l, ra)
    int cnta2 = 0, cntb2 = 0; // [l, rb)

    for (int l = 0; l < n; l++) {
        while (ra < n && cnta1 < a) {
            if (s[ra] == 'a') cnta1++;
            if (s[ra] == 'b') cntb1++;
            ra++;
        }

        while (rb < n && cntb2 < b) {
            if (s[rb] == 'a') cnta2++;
            if (s[rb] == 'b') cntb2++;
            rb++;
        }

        while (rb < ra) {
            if (s[rb] == 'a') cnta2++;
            if (s[rb] == 'b') cntb2++;
            rb++;
        }

        if (cnta1 >= a) {
            if (cntb2 < b) ans += (n - ra + 1);
            else ans += max(0, rb - ra);
        }

        if (l < ra) {
            if (s[l] == 'a') cnta1--;
            if (s[l] == 'b') cntb1--;
        }

        if (l < rb) {
            if (s[l] == 'a') cnta2--;
            if (s[l] == 'b') cntb2--;
        }
    }

    cout << ans << '\n';
    return 0;
}