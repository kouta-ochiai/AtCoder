#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << " = " << (x) << "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double d;
  cin >> d;
  double pi = acos(-1.0);
  d /= 2.0;
  cout << fixed << setprecision(7) << pi * d * d << '\n';
}
