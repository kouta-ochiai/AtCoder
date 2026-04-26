#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> S;
    while(N--) {string tmp; cin >> tmp; S.push_back(tmp);}

    set<string> T;
    for (int i = 0; i < (int)S.size(); i++){
        for (int j = 0; j < (int)S.size(); j++){
            if (i != j) {
                string tmp = "";
                tmp += S[i];
                tmp += S[j];
                T.insert(tmp);
            }
        }
    }

    cout << T.size() << '\n';
}

