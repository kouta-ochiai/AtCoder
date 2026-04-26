#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  if ((int)S.size() % 5 == 0) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
