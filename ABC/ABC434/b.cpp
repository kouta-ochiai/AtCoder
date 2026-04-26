#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<int, int> sum; // type, sum
    map<int, int> cnt; // type, cnt

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        sum[A] += B;
        cnt[A]++;
    }

    for (int i = 1; i <= M; i++) {
        if (cnt[i] == 0) continue; // 必要に応じて処理を変える
        double avg = 1.0 * sum[i] / cnt[i];
        cout << avg << '\n';
    }
}