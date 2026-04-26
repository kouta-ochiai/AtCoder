#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    vector<string> w = {"dream", "dreamer", "erase", "eraser"};

    while (!S.empty()) {
        bool ok = false;
        for (const string &t : w) {
            if (S.size() >= t.size() &&
                S.compare(S.size() - t.size(), t.size(), t) == 0) {
                S.erase(S.size() - t.size()); // 末尾を一括削除
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}