#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using P = pair<int, int>;

int N;
vector<vector<int>> A;

// path のスコア計算
ll GetScore(const vector<P>& path) {
    ll score = 0;
    for (int k = 0; k < (int)path.size(); k++) {
        auto [i, j] = path[k];
        score += 1LL * k * A[i][j];
    }
    return score;
}

// まず基本の蛇を作る
// 0行目: 左→右
// 1行目: 右→左
// 2行目: 左→右 ...
vector<P> GetSnakePath() {
    vector<P> path;
    path.reserve(N * N);

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                path.push_back({i, j});
            }
        } else {
            for (int j = N - 1; j >= 0; j--) {
                path.push_back({i, j});
            }
        }
    }
    return path;
}

// 座標変換
// rot = 0,1,2,3 : 90度回転回数
// flip = false/true : 左右反転を加える
P TransformPoint(int i, int j, int rot, bool flip) {
    // 回転
    for (int t = 0; t < rot; t++) {
        int ni = j;
        int nj = N - 1 - i;
        i = ni;
        j = nj;
    }

    // 左右反転
    if (flip) {
        j = N - 1 - j;
    }

    return {i, j};
}

vector<P> TransformPath(const vector<P>& path, int rot, bool flip) {
    vector<P> res;
    res.reserve(path.size());
    for (auto [i, j] : path) {
        res.push_back(TransformPoint(i, j, rot, flip));
    }
    return res;
}


// 合法性チェック
bool IsValidPath(const vector<P>& path) {
    if ((int)path.size() != N * N) return false;

    vector visited(N, vector<int>(N, 0));

    for (int k = 0; k < (int)path.size(); k++) {
        auto [i, j] = path[k];
        if (i < 0 || i >= N || j < 0 || j >= N) return false;
        if (visited[i][j]) return false;
        visited[i][j] = 1;

        if (k + 1 < (int)path.size()) {
            auto [ni, nj] = path[k + 1];
            if (max(abs(i - ni), abs(j - nj)) != 1) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N, vector<int>(N));
    for (auto& row : A) {
        for (auto& val : row) {
            cin >> val;
        }
    }

    vector<P> base = GetSnakePath();

    ll bestScore = -1;
    vector<P> bestPath;

    // 4回転 × 左右反転ありなし × reverseありなし
    for (int rot = 0; rot < 4; rot++) {
        for (int flip = 0; flip < 2; flip++) {
            vector<P> cand = TransformPath(base, rot, flip);

            for (int rev = 0; rev < 2; rev++) {
                vector<P> path = cand;
                if (rev) reverse(path.begin(), path.end());

                if (!IsValidPath(path)) continue;

                ll score = GetScore(path);
                if (score > bestScore) {
                    bestScore = score;
                    bestPath = path;
                }
            }
        }
    }

    // 出力
    for (auto [i, j] : bestPath) {
        cout << i << ' ' << j << '\n';
    }

    return 0;
}