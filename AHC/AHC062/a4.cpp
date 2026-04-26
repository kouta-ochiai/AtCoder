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

int SnakeIndex(int i, int j) {
    if (i % 2 == 0) return i * N + j;
    return i * N + (N - 1 - j);
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

vector<vector<pair<int, int>>> BuildTwoRowSegmentsByBand() {
    vector<vector<pair<int, int>>> byBand(max(0, N - 1));
    for (int r = 0; r + 1 < N; ++r) {
        for (int c1 = 0; c1 < N; ++c1) {
            for (int c2 = 0; c2 < N; ++c2) {
                int j1 = min(c1, c2);
                int j2 = max(c1, c2);
                int left = SnakeIndex(r, j1);
                int right = SnakeIndex(r, j2);
                int low = SnakeIndex(r + 1, j2);
                int high = SnakeIndex(r + 1, j1);
                int l = min({left, right, low, high});
                int rr = max({left, right, low, high});
                if (l < rr) byBand[r].push_back({l, rr});
            }
        }
    }
    for (auto& segs : byBand) {
        sort(segs.begin(), segs.end());
        segs.erase(unique(segs.begin(), segs.end()), segs.end());
    }
    return byBand;
}

template <class URBG>
bool TryRandomReverse(
    vector<P>& path,
    ll& currentScore,
    ll& bestScore,
    vector<P>& bestPath,
    const vector<pair<int, int>>& segs,
    double temp,
    bool hillClimbOnly,
    URBG& rng
) {
    if (segs.empty()) return false;
    uniform_int_distribution<int> distSeg(0, (int)segs.size() - 1);
    auto [l, r] = segs[distSeg(rng)];

    if (!CanReverseSegment(path, l, r)) return false;

    ll delta = ScoreDeltaIfReverse(path, l, r);
    bool accept = false;
    if (hillClimbOnly) {
        accept = delta > 0;
    } else if (delta >= 0) {
        accept = true;
    } else {
        uniform_real_distribution<double> dist01(0.0, 1.0);
        double prob = exp((double)delta / temp);
        accept = dist01(rng) < prob;
    }
    if (!accept) return false;

    reverse(path.begin() + l, path.begin() + r + 1);
    currentScore += delta;
    if (currentScore > bestScore) {
        bestScore = currentScore;
        bestPath = path;
    }
    return true;
}

template <class URBG>
double EstimateInitialTemperature(
    const vector<P>& path,
    const vector<pair<int, int>>& segs,
    URBG& rng
) {
    if (segs.empty()) return 1e3;

    const int sampleCount = 400;
    const double targetAccept = 0.3;
    ll negativeAbsSum = 0;
    int negativeCount = 0;
    uniform_int_distribution<int> distSeg(0, (int)segs.size() - 1);

    for (int iter = 0; iter < sampleCount; ++iter) {
        auto [l, r] = segs[distSeg(rng)];
        if (!CanReverseSegment(path, l, r)) continue;
        ll delta = ScoreDeltaIfReverse(path, l, r);
        if (delta < 0) {
            negativeAbsSum += -delta;
            ++negativeCount;
        }
    }

    if (negativeCount == 0) return 1e3;

    double avgNegativeAbs = (double)negativeAbsSum / negativeCount;
    double temp = avgNegativeAbs / (-log(targetAccept));
    return max(1.0, temp);
}

void BuildPositionTable(const vector<P>& path, vector<vector<int>>& pos) {
    for (int k = 0; k < (int)path.size(); ++k) {
        auto [i, j] = path[k];
        pos[i][j] = k;
    }
}

void ApplyReverseSegment(vector<P>& path, vector<vector<int>>& pos, int l, int r) {
    reverse(path.begin() + l, path.begin() + r + 1);
    for (int k = l; k <= r; ++k) {
        auto [i, j] = path[k];
        pos[i][j] = k;
    }
}

template <class URBG>
bool TryEndpointReverse(
    vector<P>& path,
    vector<vector<int>>& pos,
    ll& currentScore,
    ll& bestScore,
    vector<P>& bestPath,
    double temp,
    bool hillClimbOnly,
    URBG& rng
) {
    const int M = (int)path.size();
    if (M <= 3) return false;

    uniform_int_distribution<int> distL(1, M - 2);
    int l = distL(rng);
    P prev = path[l - 1];
    P first = path[l];

    vector<int> candidates;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) continue;
            int ni = prev.first + di;
            int nj = prev.second + dj;
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            int r = pos[ni][nj];
            if (r < l + 1 || r + 1 >= M) continue;
            if (!IsAdjacent(first, path[r + 1])) continue;
            candidates.push_back(r);
        }
    }
    if (candidates.empty()) return false;

    uniform_int_distribution<int> distPick(0, (int)candidates.size() - 1);
    int r = candidates[distPick(rng)];
    ll delta = ScoreDeltaIfReverse(path, l, r);

    bool accept = false;
    if (hillClimbOnly) {
        accept = delta > 0;
    } else if (delta >= 0) {
        accept = true;
    } else {
        uniform_real_distribution<double> dist01(0.0, 1.0);
        double prob = exp((double)delta / temp);
        accept = dist01(rng) < prob;
    }
    if (!accept) return false;

    ApplyReverseSegment(path, pos, l, r);
    currentScore += delta;
    if (currentScore > bestScore) {
        bestScore = currentScore;
        bestPath = path;
    }
    return true;
}

template <class URBG>
void RunBandHillClimb(
    vector<P>& path,
    vector<vector<int>>& pos,
    ll& currentScore,
    ll& bestScore,
    vector<P>& bestPath,
    const vector<vector<pair<int, int>>>& bands,
    URBG& rng
) {
    vector<int> order;
    for (int r = 0; r < (int)bands.size(); ++r) {
        if (!bands[r].empty()) order.push_back(r);
    }
    shuffle(order.begin(), order.end(), rng);

    for (int band : order) {
        const auto& segs = bands[band];
        vector<int> segOrder(segs.size());
        iota(segOrder.begin(), segOrder.end(), 0);
        shuffle(segOrder.begin(), segOrder.end(), rng);

        bool improved = true;
        int pass = 0;
        while (improved && pass < 2) {
            improved = false;
            for (int idx : segOrder) {
                auto [l, r] = segs[idx];
                if (!CanReverseSegment(path, l, r)) continue;
                ll delta = ScoreDeltaIfReverse(path, l, r);
                if (delta <= 0) continue;
                ApplyReverseSegment(path, pos, l, r);
                currentScore += delta;
                if (currentScore > bestScore) {
                    bestScore = currentScore;
                    bestPath = path;
                }
                improved = true;
            }
            ++pass;
            if (improved) shuffle(segOrder.begin(), segOrder.end(), rng);
        }
    }
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
    vector<vector<int>> pos(N, vector<int>(N, -1));
    BuildPositionTable(path, pos);
    const vector<vector<pair<int, int>>> twoRowBands = BuildTwoRowSegmentsByBand();
    vector<pair<int, int>> allTwoRowSegs;
    for (const auto& band : twoRowBands) {
        allTwoRowSegs.insert(allTwoRowSegs.end(), band.begin(), band.end());
    }

    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    RunBandHillClimb(path, pos, currentScore, bestScore, bestPath, twoRowBands, rng);
    path = bestPath;
    currentScore = bestScore;
    BuildPositionTable(path, pos);

    const double timeLimit = 1.85;
    const double startTemp = EstimateInitialTemperature(path, allTwoRowSegs, rng);
    const double endTemp = 1e3;
    const auto startClock = chrono::steady_clock::now();

    while (true) {
        double elapsed = chrono::duration<double>(chrono::steady_clock::now() - startClock).count();
        if (elapsed >= timeLimit) break;
        double progress = elapsed / timeLimit;
        double temp = startTemp * pow(endTemp / startTemp, progress);
        uniform_int_distribution<int> distKind(0, 99);
        bool used = false;
        if (distKind(rng) < 50) {
            used = TryEndpointReverse(path, pos, currentScore, bestScore, bestPath, temp, false, rng);
        }
        if (!used) {
            if (TryRandomReverse(path, currentScore, bestScore, bestPath, allTwoRowSegs, temp, false, rng)) {
                BuildPositionTable(path, pos);
            }
        }
    }

    path = bestPath;
    currentScore = bestScore;
    BuildPositionTable(path, pos);
    const double hillTimeLimit = 0.12;
    const auto hillStart = chrono::steady_clock::now();
    while (chrono::duration<double>(chrono::steady_clock::now() - hillStart).count() < hillTimeLimit) {
        uniform_int_distribution<int> distKind(0, 99);
        bool used = false;
        if (distKind(rng) < 70) {
            used = TryEndpointReverse(path, pos, currentScore, bestScore, bestPath, 1.0, true, rng);
        }
        if (!used) {
            if (TryRandomReverse(path, currentScore, bestScore, bestPath, allTwoRowSegs, 1.0, true, rng)) {
                BuildPositionTable(path, pos);
            }
        }
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
