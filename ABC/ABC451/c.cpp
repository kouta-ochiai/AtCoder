#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;

  priority_queue<int, vector<int>, greater<int>> st;

  while (Q--) {
    int type, h;
    cin >> type >> h;

    if (type == 1) {
      st.push(h);
    } else {
      while (!st.empty() && st.top() <= h) {
        st.pop();
      }
    }

    cout << st.size() << '\n';
  }
}
