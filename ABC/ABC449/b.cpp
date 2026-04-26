#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w, q;
  cin >> h >> w >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int r;
      cin >> r;
      cout << r * w << '\n';
      h -= r;
    }
    if (type == 2) {
      int c;
      cin >> c;
      cout << h * c << '\n';
      w -= c;
    }
  }
}
