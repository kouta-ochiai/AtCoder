#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> now(M), nxt(M);
  while (N--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    now[a]++;
    nxt[b]++;
  }
  for (int i = 0; i < M; i++) {
    cout << nxt[i] - now[i] << '\n';
  }
}
