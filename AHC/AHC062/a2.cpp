#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

namespace {

int N;
vector<vector<int>> A;

inline bool IsAdjacent(const P& a, const P& b) {
    return max(abs(a.first - b.first), abs(a.second - b.second)) == 1;
}

ll GetScore(const vector<P>& path) {
    ll score = 0;
    for (int k = 0; k < (int)path.size(); ++k) {
        auto [i, j] = path[k];
        score += 1LL * k * A[i][j];
    }
    return score;
}

vector<P> GetSnakePath() {
    vector<P> path;
    path.reserve(N * N);
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) path.push_back({i, j});
        } else {
            for (int j = N - 1; j >= 0; --j) path.push_back({i, j});
        }
    }
    return path;
}

P TransformPoint(int i, int j, int rot, bool flip) {
    for (int t = 0; t < rot; ++t) {
        int ni = j;
        int nj = N - 1 - i;
        i = ni;
        j = nj;
    }
    if (flip) j = N - 1 - j;
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

bool IsValidPath(const vector<P>& path) {
    if ((int)path.size() != N * N) return false;
    vector<vector<int>> used(N, vector<int>(N, 0));
    for (int k = 0; k < (int)path.size(); ++k) {
        auto [i, j] = path[k];
        if (i < 0 || i >= N || j < 0 || j >= N) return false;
        if (used[i][j]) return false;
        used[i][j] = 1;
        if (k + 1 < (int)path.size() && !IsAdjacent(path[k], path[k + 1])) return false;
    }
    return true;
}

bool CheckEdgeAfterSwap(const vector<P>& path, int k, int p, int q) {
    if (k < 0 || k + 1 >= (int)path.size()) return true;
    const P& left = (k == p ? path[q] : (k == q ? path[p] : path[k]));
    const P& right = (k + 1 == p ? path[q] : (k + 1 == q ? path[p] : path[k + 1]));
    return IsAdjacent(left, right);
}

bool CanSwap(const vector<P>& path, int p, int q) {
    if (p == q) return false;
    if (p > q) swap(p, q);

    vector<int> idx = {p - 1, p, q - 1, q};
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (int k : idx) {
        if (!CheckEdgeAfterSwap(path, k, p, q)) return false;
    }
    return true;
}

ll ScoreDeltaIfSwap(const vector<P>& path, int p, int q) {
    auto [i1, j1] = path[p];
    auto [i2, j2] = path[q];
    return 1LL * p * A[i2][j2] + 1LL * q * A[i1][j1]
         - 1LL * p * A[i1][j1] - 1LL * q * A[i2][j2];
}

bool CanReverseSegment(const vector<P>& path, int l, int r) {
    if (l < 0 || r >= (int)path.size() || l >= r) return false;
    if (l > 0 && !IsAdjacent(path[l - 1], path[r])) return false;
    if (r + 1 < (int)path.size() && !IsAdjacent(path[l], path[r + 1])) return false;
    return true;
}

ll ScoreDeltaIfReverse(const vector<P>& path, int l, int r) {
    ll delta = 0;
    while (l < r) {
        auto [i1, j1] = path[l];
        auto [i2, j2] = path[r];
        delta += 1LL * l * A[i2][j2] + 1LL * r * A[i1][j1]
               - 1LL * l * A[i1][j1] - 1LL * r * A[i2][j2];
        ++l;
        --r;
    }
    return delta;
}

vector<P> BuildInitialPath() {
    vector<P> base = GetSnakePath();
    ll bestScore = numeric_limits<ll>::min();
    vector<P> bestPath;

    for (int rot = 0; rot < 4; ++rot) {
        for (int flip = 0; flip < 2; ++flip) {
            vector<P> cand = TransformPath(base, rot, flip);
            for (int rev = 0; rev < 2; ++rev) {
                vector<P> path = cand;
                if (rev) reverse(path.begin(), path.end());
                if (!IsValidPath(path)) continue;
                ll score = GetScore(path);
                if (score > bestScore) {
                    bestScore = score;
                    bestPath = move(path);
                }
            }
        }
    }
    return bestPath;
}

vector<P> SolveBySA() {
    vector<P> path = BuildInitialPath();
    if (N == 1) return path;

    ll currentScore = GetScore(path);
    ll bestScore = currentScore;
    vector<P> bestPath = path;

    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distRow(0, max(0, N - 2));
    uniform_int_distribution<int> distCol(0, N - 1);
    uniform_real_distribution<double> dist01(0.0, 1.0);

    const double timeLimit = 1.9;
    const double startTemp = 2e6;
    const double endTemp = 1e3;
    const auto startClock = chrono::steady_clock::now();

    int iter = 0;
    while (true) {
        double elapsed = chrono::duration<double>(chrono::steady_clock::now() - startClock).count();
        if (elapsed >= timeLimit) break;
        double progress = elapsed / timeLimit;
        double temp = startTemp * pow(endTemp / startTemp, progress);

        int r = distRow(rng);
        int c1 = distCol(rng);
        int c2 = distCol(rng);
        int j1 = min(c1, c2);
        int j2 = max(c1, c2);

        int left = r * N + j1;
        int right = r * N + j2;
        int low = (r + 1) * N + (N - 1 - j2);
        int high = (r + 1) * N + (N - 1 - j1);
        int l = min({left, right, low, high});
        int rr = max({left, right, low, high});
        if (l >= rr) continue;

        if (!CanReverseSegment(path, l, rr)) continue;

        ll delta = ScoreDeltaIfReverse(path, l, rr);
        bool accept = false;
        if (delta >= 0) {
            accept = true;
        } else {
            double prob = exp((double)delta / temp);
            accept = dist01(rng) < prob;
        }

        if (!accept) continue;

        reverse(path.begin() + l, path.begin() + rr + 1);
        currentScore += delta;
        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestPath = path;
        }
        ++iter;
    }

    return bestPath;
}

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N, vector<int>(N));
    for (auto& row : A) {
        for (auto& x : row) cin >> x;
    }

    vector<P> ans = SolveBySA();
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << '\n';
    }
    return 0;
}
