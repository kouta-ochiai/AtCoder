#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, -1));
    int r = 0, c = (N - 1) / 2, k = 1;

    A[r][c] = k;
    int cnt = N * N - 1;

    while (cnt--) {
        int nr = (r - 1 + N) % N;
        int nc = (c + 1) % N;
        k++;

        if (A[nr][nc] == -1) {
            r = nr;
            c = nc;
        } else {
            r = (r + 1) % N;
        }

        A[r][c] = k;
    }

    for (const auto &row : A) {
        for (const auto &val : row) cout << val << ' ';
        cout << '\n';
    }
}