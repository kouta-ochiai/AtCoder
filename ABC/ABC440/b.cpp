#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> T; // index, time

    for (int i = 0; i < N; i++){
        int t;
        cin >> t;
        T.push_back({i+1, t}); // 1-index
    }

    sort(T.begin(), T.end(), [](const auto &a, const auto &b){
        return a.second < b.second;
        if (a.second != b.second) return a.first < b.first;
    });
   
    for (int i = 0; i < 3; i++){
        cout << T[i].first << " ";
    }

    cout << '\n';
}

