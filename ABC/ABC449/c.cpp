#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;

  ll ans = 0;
  int del = r - l;
  vector<int> cnt(26, 0);

  for (int i = 0; i < del; i++) {
    cnt[s[i] - 'a']++;
  }

  for (int val : cnt) {
    if (val >= 2)
      ans += val;
  }

  for (int i = del; i < n; i++) {
    cnt[s[i - del] - 'a']--;
    cnt[s[i] - 'a']++;

    for (int val : cnt) {
      if (val >= 2)
        ans++;
    }
  }

  cout << ans << '\n';
}
