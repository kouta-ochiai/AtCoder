#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    cin >> N;
    set<int> type;
    int sum = 0;
    while (sum != 1){
        int tmp = 0;
        for (char c: N){
            tmp += int(c - '0') * int(c - '0');
        }
        sum = tmp;
        dbg(sum);
        N = to_string(sum);
        if (type.count(sum)) {
            cout << "No\n";
            return 0;
        }
        type.insert(sum);
    }
    cout << "Yes\n";
    return 0;
   
}

