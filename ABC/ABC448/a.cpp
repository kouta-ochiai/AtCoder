#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int &a : A)
    cin >> a;

  for (int i = 0; i < N; i++) {
    if (A[i] < X) {
      X = A[i];
      cout << '1' << '\n';
    } else {
      cout << '0' << '\n';
    }
  }
}
